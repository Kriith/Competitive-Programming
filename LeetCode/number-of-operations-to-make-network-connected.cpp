class Solution {
public:
    struct dsu{
        int components;
        vector<int> data;
        dsu(int n = -1){
            if(n >= 0){
                data.assign(n, -1);
                components = n;
            }
        }

        int find(int x){
            return data[x] < 0?x:data[x] = find(data[x]);
        }

        bool merge(int x, int y){
            x = find(x), y = find(y);
            if(x == y) return false;
            if(-data[x] < -data[y]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
            components--;
            return true;
        }
        
        int getcomponents(){
            return components;
        }
    };

    int makeConnected(int n, vector<vector<int>>& connections) {
        int e = connections.size();
        if(e < n - 1) return -1;
        dsu s(n);
        for(auto i: connections){
            s.merge(i[0], i[1]);
        }
        return s.getcomponents() - 1;
    }
};