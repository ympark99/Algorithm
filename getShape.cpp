#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{   //프로그램의 시작부 
		//첫 번째 점 P의 좌표 
		int px, py;
		//두 번째 점 Q의 좌표
		int qx, qy;
		scanf("%d %d", &px, &py);
		scanf("%d %d", &qx, &qy);
	
	if(px == qx && py == qy)
			printf("DOT\n");
	else if((px == qx && py != qy) || (px != qx && py == qy))
			printf("SEGMENT\n");
	else if(abs(px-qx) == abs(py-qy))
			printf("SQUARE\n");
	else printf("RECTANGLE\n");
	
    return 0;
}
