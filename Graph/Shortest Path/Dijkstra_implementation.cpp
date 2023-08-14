#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 5;
const int INF = 1e9 + 10;
vector<pii> adj[N];
vector<int> dist(N, INF);
vector<bool> visited(N);

void dijkstra(int source)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    /*
    প্রথমে একটা প্রাইওরিটি কিউ নিয়েছি, পেয়ারের৷ আর গ্রেটার ইউজ করেছি, কারণ আমরা ভেল্যুগুলো ছোট থেকে বড় কম্পেয়ার করব। প্রাইওরিটি কিউতে বাই ডিফল্ট বড় থেকে ছোট আকারে ভেল্যু বের হয়।
    */
    dist[source] = 0;
    /*
    এবার সোর্স যেই নোডটা দেওয়া আছে আমাদের, তার ডিসটেন্স ০ সেট করে নিব। মাতলাব, যেই নোড থেকে ডিসটেন্স হিসাব করব, সেটার ডিসটেন্স ০ ধরে নিলাম।
    */
    pq.push({dist[source], source});
    /*
    1)
    কিউতে এবার, ঐ সোর্স নোডটা আর তার ডিসটেন্স (যেটা মাত্র ০ সেট করলাম) সেটা পুশ করব। পুশ করার সময় ডিসটেন্সটা আগে রাখলাম, আর সোর্স নোডটা পরে (পেয়ার মেক করার সময়)। কারণ পেয়ার বাই ডিফল্ট প্রথম ভেল্যু অনুযায়ী সর্টেড হয়। যেহেতু আমরা ডিসটেন্সটা কম্পেয়ার করব (মানে শর্টেস্ট পাথ), তাই।
    */

    /*
    এবার হোয়াইল লুপ চালাব। কিউ যতক্ষণ খালি না হবে ততক্ষণ।
    */
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        /*
        2)
        সবার আগে কিউ এর প্রথম ভেল্যুটা নিব। কিউতে যেহেতু পেয়ার আছে (ডিসটেন্স+নোড), আমরা শুধু সেকেন্ড ভেল্যু মানে নোডটা নিয়ে কাজ করব। প্রথম ভেল্যু মানে ডিসটেন্স এর এখানে কোনো কাজ নেই। এবার এটা কিউ থেকে পপ করে দিব। আর নোডটা ভিজিটেড করে দিব।
        */
        /*
        **এখানে একটু বুঝুন। নোডটাকে ভিজিটেড +পপ কেন করে দিচ্ছি। কারণ, প্রাইওরিটি কিউ আমরা ছোট থেকে বড় আকারে সেট করেছি। যদি এই নোডের আরো ছোট কোনো পাথ থাকত, তাহলে সেটাই আগে আসত। এটা আগে এসেছে মানে এটাই সবচেয়ে ছোট পাথ, বা এটাই একমাত্র পাথ। তো এই নোডের আরো কোনো পাথ যদি কিউতে থাকে, তাহলেও কোনো ফায়দা নেই। কারণ, ওটা অবশ্যই বড় পাথ হবে। আমাদের ছোট পাথটা দরকার, সেটা আমরা পেয়ে গেছি।
        */

        /*
        এবার আরেকটা লুপ চালাব। যেই নোডটা পেয়েছি, সেটা থেকে আর কোন কোন নোডে যাওয়া যায় সেটা খুঁজতে।
        */
        for (pii vpair : adj[u])
        {
            int v = vpair.first;
            int w = vpair.second;
            /*
            3)
            খেয়াল করুন, ইনপুট নেওয়ার সময় আমরা ভেক্টরে পেয়ার মাতলাব ২ টা ভেল্যু পুশ করেছি প্রতিটা ইনডেক্সে। একটা নোড, আরেকটা ওয়েট। সেজন্য এখন ২ টা ইন্টিজার নিয়ে, একটাতে নোডটা রাখব (first), আরেকটাতে ওয়েট(second)। ভেল্যুগুলো পেয়ার থেকে আলাদা করলাম আর কী।
            */

            if (visited[v])
                continue;
            /*
            এখন চেক করব, এই নোডটা অলরেডি ভিজিটেড নাকি। অলরেডি ভিজিটেড হলে ইগনোর করব।
            */

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
            /*
            4)
            আর যদি ভিজিটেড না হয়, তাহলে চেক করব, নোডের আগের ডিসটেন্স এর থেকে বর্তমান ডিসটেন্সটা বড় নাকি ছোট। ছোট হলে আমরা ডিাটেন্স আপডেট করব। আর বড় হলে কিছু করার প্রয়োজন নেই। তারপর এটা আবার কিউতে পুশ করব। নতুন ডিসটেন্সটা+নোডটা।
            বর্তমান ডিসটেন্সটা হিসাব হবে, আমাদের প্যারেন্ট নোড এর ডিসটেন্স এর সাথে, প্যারেন্ট থেকে এই নোডে আসতে যেই কস্টটা লাগবে বা ওয়েটটা দেওয়া আছে সেটা যোগ করে।
            */
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of node " << i << ": " << dist[i] << endl;
    }
    return 0;
}
