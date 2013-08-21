#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > pairs;
vector<pair<int, int> > result;
int leftMost, rightMost;
int main()
{
	int i, j, testN, from, to, counter, bestR, bestL;
	scanf("%d",&testN);
	while(testN--)
	{
		scanf("%d",&rightMost);
		leftMost = 0;
		scanf("%d %d",&from,&to);
		while(from != 0 || to != 0)
		{
			pairs.push_back(make_pair(min(from, to), max(from, to)));
			scanf("%d %d",&from,&to);
		}
		counter = 0;
		while(leftMost < rightMost)
		{
			bestR = -1;
			for(i=0; i<pairs.size(); i++)
			{
				if(pairs[i].first <= leftMost && pairs[i].second > bestR)
				{
					bestL = pairs[i].first;
					bestR = pairs[i].second;
				}
			}
			if(bestR > 0)
			{
				result.push_back(make_pair(bestL, bestR));
				counter ++;
				leftMost = bestR;
			}
			else
			{
				counter = 0;
				break;
			}
		}
		printf("%d\n", counter);
		for(i=0; i<counter; i++)
		{
			printf("%d %d\n", result[i].first, result[i].second);
		}
		pairs.clear();
		result.clear();
		if(testN != 0)
		{
			printf("\n");
		}
	}
	return 0;
}
