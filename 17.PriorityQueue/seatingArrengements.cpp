#include <bits/stdc++.h>
#define int long long
using namespace std;

unordered_map<int, int> mp;

class Compare
{
public:
    bool operator()(pair<int, int> i1, pair<int, int> i2)
    {
        if (i1.first == i2.first)
            return i1.second > i2.second;
        return i1.first < i2.first;
    }
};

void makeSeatingArrengements(int n, int k, string pref)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq; //stores size, startIndex
    pq.push({n, 0});
    for (int i = 1; i <= k; i++)
    {
        auto avail = pq.top();
        pq.pop();
        int start = avail.second;
        int end = avail.first + avail.second - 1;
        if ((start + end) % 2 == 0)
        {
            //even sum
            int mid = (start + end) / 2;
            mp.insert(make_pair(mid + 1, i));
            if ((mid - 1) >= start)
            {
                pq.push({mid - start, start});
            }
            if ((mid + 1) <= end)
            {
                pq.push({end - mid, mid + 1});
            }
        }
        else
        {
            //odd sum
            int leftMid = (start + end) / 2;
            int rightMid = leftMid + 1;
            if (pref[i - 1] == 'L')
            {
                //pick the left of the mid's
                mp.insert(make_pair(leftMid + 1, i));
                if ((leftMid - 1) >= start)
                {
                    pq.push({leftMid - start, start});
                }
                if ((leftMid + 1) <= end)
                {
                    pq.push({end - leftMid, leftMid + 1});
                }
            }
            else
            {
                //pick the right of the mid's
                mp.insert(make_pair(rightMid + 1, i));
                if ((rightMid - 1) >= start)
                {
                    pq.push({rightMid - start, start});
                }
                if ((rightMid + 1) <= end)
                {
                    pq.push({end - rightMid, rightMid + 1});
                }
            }
        }
    }
}

signed main()
{
    int n, k;
    cin >> n >> k;
    string preference;
    cin >> preference;
    makeSeatingArrengements(n, k, preference);
    int query;
    cin >> query;
    while (query--)
    {
        int q;
        cin >> q;
        if (mp.find(q) != mp.end())
        {
            cout << mp[q] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}