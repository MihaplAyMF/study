// usedma.cpp -- inheritance, friends, and DMA
// compile with dma.cpp
#include <iostream>
#include "dma.h"
int main()
{
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    cout << "Displaying baseDMA object:\n";
    cout << shirt << endl;
    cout << "Displaying lacksDMA object:\n";
    cout << balloon << endl;
    cout << "Displaying hasDMA object:\n";
    cout << map << endl;
    lacksDMA balloon2(balloon);
    cout << "Result of lacksDMA copy:\n";
    cout << balloon2 << endl;
    hasDMA map2;
    map2 = map;
    cout << "Result of hasDMA assignment:\n";
    cout << map2 << endl;
    // std::cin.get();
    return 0; 
}
*÷¸öÒ~ eµùKzâ·Ý[bBLÜZ¥ž±ší=5”ÍþßÎ¾~*+vPætÚÖß¹ëµ]kÓ¨%ìrÆcm ¶c¤m5­ç×Y•às…Öe„k,°ë§¦‘Ÿ ÏµÍ²7ó;q*s˜±ÂÆÕ¼va[ª×f».ã3_‚íwRP15njœá.û…ÿ=÷¹¡Ð_cÊ‹uÎÕ¦«cÍÚß‚|òþÛüÂÇ¶*û›‰¶­Ðgf„­®&_F­™.ëe×¯"x-t¹“€µ!¢Žp[1š.îJŠÀ§‘éâ¦o£_¦¥
sé½ arô