#define ll long long 

ll n;

vector<pair<int,int>> cache;

map<int,int> mp;

LRUCache::LRUCache(int capacity) {

    n = capacity;

    cache.clear();

    mp.clear();

}



int LRUCache::get(int key) {

    if(mp.find(key)==mp.end()){ return -1; }

    ll partner = mp[key];

    pair<int,int> p = make_pair(key,partner);

    vector<pair<int,int>>:: iterator it;

    it = find(cache.begin(),cache.end(),p);

    if(it==cache.end())

    { return -1; }

    else

    { cache.erase(it);cache.push_back(p); return partner; }

}



void LRUCache::set(int key, int value) {

    if(mp.find(key)==mp.end())

    {

        if(cache.size()==n){ cache.erase(cache.begin()); }

        cache.push_back(make_pair(key,value));

    }

    else

    {

        vector<pair<int,int>>:: iterator it;

        pair<int,int> p = make_pair(key,mp[key]);

        it = find(cache.begin(),cache.end(),p);

        if(it!=cache.end())

        { cache.erase(it); }

        else

        { if(cache.size()==n){ cache.erase(cache.begin()); } }

        cache.push_back(make_pair(key,value));

    }

    mp[key] = value;

}