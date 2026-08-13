class MovieRentingSystem {
private:
    // (shop, movie) -> price
    unordered_map<long long, int> priceMap;
    
    // movie -> set of {price, shop} for UNRENTED copies
    unordered_map<int, set<pair<int,int>>> unrented;
    
    // set of {price, shop, movie} for RENTED copies
    set<tuple<int,int,int>> rentedSet;
    
    long long key(int shop, int movie) {
        return (long long)shop * 1000000LL + movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[key(shop, movie)] = price;
            unrented[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        if (unrented.find(movie) == unrented.end()) return res;
        
        int count = 0;
        for (auto& [price, shop] : unrented[movie]) {
            res.push_back(shop);
            if (++count == 5) break;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = priceMap[key(shop, movie)];
        unrented[movie].erase({price, shop});
        rentedSet.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = priceMap[key(shop, movie)];
        rentedSet.erase({price, shop, movie});
        unrented[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count = 0;
        for (auto& [price, shop, movie] : rentedSet) {
            res.push_back({shop, movie});
            if (++count == 5) break;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */