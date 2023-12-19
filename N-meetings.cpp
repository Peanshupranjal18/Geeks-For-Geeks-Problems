Expected Approach(Greedy)
    Intuition : The idea is to sort the meetings based on their end times.We can then greedily select meetings that end early,
    allowing us to accommodate more meetings overall.

    Implementation : Create pairs of meetings with their start and end times.Sort the meetings based on their end times.Iterate through the sorted meetings and keep track of the last end time.If the current meeting start time is after the last end time,
    select the meeting.

    Code

    class Solution
{
public:
    // comparator function used in sorting the list of pairs
    // according to increasing order of the finish time.
    static bool pairCompare(const pair<pair<int, int>, int> &a,
                            const pair<pair<int, int>, int> &b)
    {
        if (a.first.second != b.first.second)
        {
            return a.first.second < b.first.second;
        }
        return a.second < b.second;
    }

    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {

        vector<pair<pair<int, int>, int>> x;

        // pushing the pair of starting and finish time and their
        // index as pair in another list.
        for (int i = 0; i < n; i++)
            x.push_back({{start[i], end[i]}, i + 1});

        // sorting the list.
        sort(x.begin(), x.end(), pairCompare);
        int last = -1;
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            // if the start time of this meeting is greater than or equal
            // to the finish time of previously selected meeting then
            // we increment the counter and update last.
            if (x[i].first.first > last)
            {
                res++;
                last = x[i].first.second;
            }
        }
        // returning the counter.
        return res;
    }
};