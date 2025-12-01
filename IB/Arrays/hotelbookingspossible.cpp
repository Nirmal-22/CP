struct Event 
{
    int date;
    int type; // 1 for arrival, -1 for departure
};

bool compareEvents(const Event& a, const Event& b) {
    if (a.date != b.date)
        return a.date < b.date;
    return a.type > b.type; // Handle departures before arrivals on the same date
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int N = arrive.size();
    std::vector<Event> events;

    for (int i = 0; i < N; ++i) 
    {
        events.push_back({arrive[i], 1});  // Arrival event
        events.push_back({depart[i], -1}); // Departure event
    }

    std::sort(events.begin(), events.end(), compareEvents);

    int roomsNeeded = 0;
    for (const Event& event : events) 
    {
        roomsNeeded += event.type;
        if (roomsNeeded > K) 
        {
            return false;
        }
    }

    return true;
}
