
            else{
                if(vis[nx][tt + k]) return "NO";
                else vis[nx][tt + k] = 1;
            }
            a = p[nx];
        }
    }
    return "YES";