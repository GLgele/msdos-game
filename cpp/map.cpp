#ifndef _MAP_CPP_
#define _MAP_CPP_

#include "../head/map.h"
using namespace std;

map::map()
{

}

map::map(int ID,string n,int acrs,int dn,int* m,int l,int ne)
{
    id = ID;
    name = n;
    across = acrs;
    down = dn;
    lastID = l;
    nextID = ne;
    mapp = new int[across*down];
    for(int i=0;i<down;i++)
    {
        for(int j=0;j<across;j++)
        {
            mapp = m+i*across+j;
            if(*mapp == 8)
            {
                pposx = j;
                pposy = i;
            }
            mapp++;
        }
    }
    mapp -= across*down;
}

#endif