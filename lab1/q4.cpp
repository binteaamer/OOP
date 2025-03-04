/*You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the
container contains the most water. Return the maximum amount of water a
container can store. Notice that you may not slant the container.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array
[1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
container can contain is 49.*/

#include <iostream>
using namespace std;

int main()
{
    int height[]={1,8,6,2,5,4,8,3,7};
    int size = sizeof(height)/ sizeof(height[0]);
    int i=0, j=size-1;
    int maxArea=0;

    while(i<j){
        int width = j-i;

        int containerHeight;

        if(height[i]<height[j])

       { containerHeight=height[i];
        i++;}

        else {containerHeight=height[j];
        j--; }

      int area= containerHeight*width;

      if(area>maxArea)

      maxArea=area;
}
   
cout << "Maximum area: " << maxArea;
return 0;
}



