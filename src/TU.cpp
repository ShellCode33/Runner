#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Drapeau

#include <boost/test/unit_test.hpp>

#include "Drapeau.h"

// les tests groupes par "cas"

BOOST_AUTO_TEST_CASE(test_estDrapeau)
{
    const int MAX = 10;
    int t1[MAX]={0,0,0,0,0,0,0,1,1,1};
    int t2[MAX]={0,0,0,0,0,1,0,1,0,1};
    int t3[MAX]={0,0,0,0,0,0,0,0,0,0};
    int t4[MAX]={1,1,1,1,1,1,1,1,1,1};

    BOOST_CHECK(estDrapeau(t1,MAX) == true);
    BOOST_CHECK(estDrapeau(t2,MAX) == false);
    BOOST_CHECK(estDrapeau(t3,MAX) == true);
    BOOST_CHECK(estDrapeau(t4,MAX) == true);
}
