#include "utils.h"

using namespace std;

Utils::Utils()
{

}

Utils::~Utils()
{

}

float Utils::randRange(float a, float b)
{
    return ( rand()/(float)RAND_MAX ) * (b-a) + a;
}

void Utils::log(const string text)
{
    time_t t = time(0);   // get time now
    struct tm * current_time = localtime(&t);

    cout << "[" << current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec << "] " << text << endl;
}



void Utils::addScore(unsigned long score, string pseudo)
{
    if(score == 0 || pseudo.size() <= 0)
        return;

    cout << "Ajout du score..." << endl;

    //On lit tous les octets du fichier de score
    ifstream file("scores", ios::binary | ios::ate);
    char *content;
    int content_size = 0;

    if(file.is_open())
    {
        content_size = file.tellg(); //file size
        content = new char[content_size+1]; //On prévoit un octet pour un \0
        content[content_size] = '\0';
        file.seekg(0, ios::beg); //reset cursor pos
        file.read(content, content_size);
        file.close();

        //On déchiffre le contenu à l'aide d'un xor par 42 ;)
        int i;
        for(i = 0; i < content_size; i++)
            content[i] ^= 42;


        //On convertit le tableau d'octets en string
        string lines[MAX_BEST_SCORES]; //10 meilleurs scores

        int nb_scores = 0; //nb de scores déjà enregistrés

        i = 0;
        int j;
        for(j = 0; j < MAX_BEST_SCORES; j++, i++) //i++ skip \n
        {
            if(content[i] == '\0')
                break;

            while(content[i] != '\n')
                lines[j] += content[i++];

            lines[j] += "\n"; //On ajoute quand meme le retour à la ligne
            nb_scores++;
        }


        //On détermine la position du nouveau score
        string line_score_str;
        unsigned long line_score = ULONG_MAX;

        for(j = 0; j < MAX_BEST_SCORES && line_score >= score; j++)
        {
            line_score_str = lines[j].substr(0, lines[j].find(":")); //split sur :
            line_score = strtoul(line_score_str.c_str(), NULL, 0); // string -> unsigned long
        }

        //Si la boucle précédente s'est arrêtée car un score plus faible que le nouveau a été trouvé
        if(line_score < score)
        {
            j--; //On repositionne dans le tableau pour que j représente la position à laquelle devrait être le score (0 -> premier)

            if(nb_scores == MAX_BEST_SCORES)
                nb_scores--; //Va permettre de supprimer la dernière valeur

            //On insère le nouveau score et supprime le dernier
            for(i = nb_scores-1; i >= j; i--)
                lines[i+1] = lines[i]; //on décale les scores

            lines[j] = to_string(score) + ":" + pseudo + "\n";
            nb_scores++;
        }

        else //Le nouveau score n'est pas dans le top MAX_BEST_SCORES
        {
            delete [] content;
            return; //On stop la fonction
        }

        //on refait le tableau à la bonne taille pour recevoir le nouveau score
        delete [] content;
        content_size += lines[j].size();
        content = new char[content_size+1]; //On prévoit un octet pour un \0
        memset(content, 0, content_size+1); //On reset le tableau à 0

        //On remet les lignes sous forme de tableau de bytes
        int content_index = 0;

        for(i = 0; i < nb_scores; i++)
            for(j = 0; j < (int)lines[i].size(); j++, content_index++)
                content[content_index] = lines[i].at(j);
    }

    else //Le fichier n'a pas pu être ouvert, il n'existe probablement pas (ou problème de permissions)
    {
        cout << "Le fichier n'existe pas, on détermine la nouvelle ligne de score" << endl;
        string score_str;
        score_str += to_string(score) + ":" + pseudo + "\n";
        content_size = score_str.size();
        content = new char[content_size];

        int i;
        for(i = 0; i < content_size; i++)
            content[i] = score_str.at(i);
    }

    //On chiffre de nouveau avant de remettre dans le fichier
    int i;
    for(i = 0; i < content_size; i++)
        content[i] ^= 42;

    //On remet le content dans le fichier
    ofstream fout;
    fout.open("scores", ios::binary | ios::out);
    fout.write(content, content_size);
    fout.close();

    delete [] content;
}

vector<pair<unsigned long, string> > Utils::getScores() //ATTENTION A BIEN DELETE CE QUE RETOURNE CETTE FONCTION
{
    vector<pair<unsigned long, std::string> > scores;
    ifstream file("scores", ios::binary | ios::ate);
    char *content;
    int content_size = 0;

    if(file.is_open())
    {
        content_size = file.tellg(); //file size
        content = new char[content_size+1]; //On prévoit un octet pour un \0
        content[content_size] = '\0';
        file.seekg(0, ios::beg); //reset cursor pos
        file.read(content, content_size);
        file.close();

        //déchiffre
        int i;
        for(i = 0; i < content_size; i++)
            content[i] ^= 42;

        i = 0;
        int num_score = 0;

        while(content[i] != '\0')
        {
            string line = "";

            while(content[i] != '\n')
                line += content[i++];

            i++; //skip \n

            string line_score_str = line.substr(0, line.find(":")); //split sur :
            pair<unsigned long, std::string> score;
            score.first = strtoul(line_score_str.c_str(), NULL, 0); // string -> unsigned long
            score.second = line.substr(line.find(":")+1, line.size()-line.find(":")); //split sur :
            scores.push_back(score);

            num_score++;
        }

        delete [] content;

    }

    return scores;
}

vector<string> Utils::getAvailableLanguages()
{
    vector<string> lang;
    #ifdef linux
    //POSIX Standard
    struct dirent *ep;
    DIR* dp = opendir ("lang/");

    if(dp != NULL)
    {
        while(ep = readdir (dp))
            lang.push_back(string(ep->d_name));

        closedir(dp);
    }

    #else
        lang.push_back("fr");
        lang.push_back("en");
        lang.push_back("es");
    #endif

    return lang;
}

string Utils::translate(string lang, string code)
{
    ifstream file("lang/" + lang);
    string traduction = code;

    if(file.is_open())
    {
        string current_line;

        while(getline(file, current_line))
        {
            if(current_line.substr(0, current_line.find('=')) == code)
            {
                traduction = current_line.substr(current_line.find('=')+1, current_line.size() - 1);
                break;
            }
        }

        file.close();
    }

    else
        Utils::log("Error while opening lang file");

    return traduction; //Si on a pas trouvé on retourne le code demandé
}
