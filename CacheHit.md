### 캐시 히트
캐시 히트율이란 프로그램 실행 중 데이터를 읽어올 때 캐시에서 읽어올 수 있는 비율을 뜻한다.  
연속된 자료구조일수록 캐시 히트율이 높다.  
예를 들면 다음과 같다.  
`arr[10]`은 `linked_list(10)`과 다르게 메모리의 연속된 공간을 차지한다.  
만약 둘을 반복문으로 `print()`해야 한다면, `arr[10]`이 더 적은 시간을 기록한다.  
문제를 통해 캐시 히트가 런타임에 미치는 영향을 알아보자.  
<br><br>
https://atcoder.jp/contests/abc378/tasks/abc378_d  
이 문제는 DFS를 통해 가능한 모든 경로를 구하는 문제이다.  
dfs함수의 재귀 호출 과정에서 `visited`배열에 대해 call by value를 활용하여 독립적인 경로를 유지해야 한다.  
다음은 정답 코드이다.
```cpp
#include <bits/stdc++.h>

#define X first 
#define Y second 
#define all(v) v.begin(),v.end()
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

int h,w,k;
int ans=0;
string b[10];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void inline DFS(pair<int,int> pos, vector<vector<bool>> vis, int d)
{
    vis[pos.X][pos.Y]=true;
    if(d==k) {
        ans++;
        return;
    }
    for(int i=0; i<4; i++)
    {
        int x = pos.X+dx[i];
        int y = pos.Y+dy[i];
        if(x<0 or x>=h or y<0 or y>=w) continue;
        if(b[x][y]=='#' or vis[x][y]) continue;
        DFS({x,y},vis,d+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>h>>w>>k;
    for(int i=0; i<h; i++) {
        cin>>b[i];
    }
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            vector<vector<bool>> vis(h,vector<bool>(w,false));
            if(b[i][j]=='#') continue;
            DFS(make_pair(i,j),vis,0);
        }
    }
    cout<<ans;
    return 0;
}
```
이 코드의 경우, 모든 입력에 대해 올바른 결과가 출력된다.  
그러나 실행 시간은 총 2050ms로, 이 문제의 제한 시간인 2000ms를 넘어간다. (atcoder 채점 서버 기준)  
그렇다면 어떻게 실행 시간을 줄일 수 있을까?  
이를 위해서는, 어디에서 가장 많은 시간을 소비하는지를 알아봐야 한다.  
가장 시간이 많이 걸리는 최악의 데이터를 넣어보자.  
```
10 10 11
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
```
이 데이터를 넣었을 때, 코드의 어느 부분에서 많은 시간을 쓰는지 알아보자.  
```
Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
  7.39      0.65     0.65 65776160     0.00     0.00  std::_Bit_iterator std::__copy_move<false, false, std::random_access_iterator_tag>::__copy_m<std::_Bit_const_iterator, std::_Bit_iterator>(std::_Bit_const_iterator, std::_Bit_const_iterator, std::_Bit_iterator)
  6.71      1.24     0.59 131552320     0.00     0.00  std::vector<bool, std::allocator<bool> >::end() const
  5.69      1.74     0.50 131552320     0.00     0.00  std::vector<bool, std::allocator<bool> >::begin() const
  5.57      2.23     0.49 664339116     0.00     0.00  std::_Bit_reference::operator=(bool)
  5.35      2.70     0.47 657761600     0.00     0.00  std::_Bit_const_iterator::operator*() const
  5.23      3.16     0.46 674459652     0.00     0.00  std::_Bit_iterator::operator*() const
  5.12      3.61     0.45 1332221252     0.00     0.00  std::_Bit_reference::_Bit_reference(unsigned long*, unsigned long)
  4.78      4.03     0.42 82474312     0.00     0.00  std::operator+(std::_Bit_iterator const&, long)
  4.21      4.40     0.37 1315523200     0.00     0.00  std::_Bit_iterator_base::_M_bump_up()
  4.10      4.76     0.36 806012472     0.00     0.00  std::_Bit_iterator_base::_Bit_iterator_base(unsigned long*, unsigned int)
  4.10      5.12     0.36 657761600     0.00     0.00  std::_Bit_const_iterator::operator++()
  3.64      5.44     0.32 65776160     0.00     0.00  std::vector<bool, std::allocator<bool> >::_M_copy_aligned(std::_Bit_const_iterator, std::_Bit_const_iterator, std::_Bit_iterator)
  3.53      5.75     0.31 82474212     0.00     0.00  std::vector<bool, std::allocator<bool> >::begin()
  3.19      6.03     0.28 657761600     0.00     0.00  std::_Bit_iterator::operator++()
  3.19      6.31     0.28 65776260     0.00     0.00  std::_Bvector_base<std::allocator<bool> >::_Bvector_impl_data::_M_reset()
  2.96      6.57     0.26 65776160     0.00     0.00  std::vector<bool, std::allocator<bool> >::vector(std::vector<bool, std::allocator<bool> > const&)
  2.73      6.81     0.24 667882136     0.00     0.00  std::_Bit_reference::operator bool() const
  1.82      6.97     0.16 65776160     0.00     0.00  std::_Bit_iterator std::__copy_move_a<false, std::_Bit_const_iterator, std::_Bit_iterator>(std::_Bit_const_iterator, std::_Bit_const_iterator, std::_Bit_iterator)
  1.59      7.11     0.14  6577516     0.00     0.00  std::vector<bool, std::allocator<bool> >* std::__do_uninit_copy<__gnu_cxx::__normal_iterator<std::vector<bool, std::allocator<bool> > const*, std::vector<std::vector<bool, std::allocator<bool> >, std::allocator<std::vector<bool, std::allocator<bool> > > > >, std::vector<bool, std::allocator<bool> >*>(__gnu_cxx::__normal_iterator<std::vector<bool, std::allocator<bool> > const*, std::vector<std::vector<bool, std::allocator<bool> >, std::allocator<std::vector<bool, std::allocator<bool> > > > >, __gnu_cxx::__normal_iterator<std::vector<bool, std::allocator<bool> > const*, std::vector<std::vector<bool, std::allocator<bool> >, std::allocator<std::vector<bool, std::allocator<bool> > > > >, std::vector<bool, std::allocator<bool> >*)
  1.02      7.20     0.09 214026632     0.00     0.00  std::_Bit_iterator::_Bit_iterator(unsigned long*, unsigned int)
  0.91      7.28     0.08 263105040     0.00     0.00  std::_Bit_iterator::_Bit_iterator()
  0.91      7.36     0.08 131552520     0.00     0.00  std::_Bvector_base<std::allocator<bool> >::_S_nword(unsigned long)
  0.91      7.44     0.08 65776260     0.00     0.00  std::vector<bool, std::allocator<bool> >::_M_initialize(unsigned long)
  0.80      7.51     0.07 131552320     0.00     0.00  std::operator-(std::_Bit_iterator_base const&, std::_Bit_iterator_base const&)
  0.80      7.58     0.07 65776160     0.00     0.00  unsigned long* std::__copy_move_a<false, unsigned long*, unsigned long*>(unsigned long*, unsigned long*, unsigned long*)
  0.80      7.65     0.07 65776160     0.00     0.00  std::_Bit_iterator std::copy<std::_Bit_const_iterator, std::_Bit_iterator>(std::_Bit_const_iterator, std::_Bit_const_iterator, std::_Bit_iterator)
  0.80      7.72     0.07      100     0.70    87.60  DFS(std::pair<int, int>, std::vector<std::vector<bool, std::allocator<bool> >, std::allocator<std::vector<bool, std::allocator<bool> > > >, int)
```
더 많은 데이터가 있지만, 여기까지만으로도 알 수 있는 것이 있다.  
문제 조건상, `DFS()`함수의 실행 횟수를 줄일 수 없다.  
그렇다면 함수 호출 한 번당 드는 시간을 줄여야 하고, 실제 시간 데이터상으로도 그렇다.  
현재 call by value로 `std::vector<std::vector<bool>>`을 전달하면서 사용하는 시간은 10초가 넘어간다. (local 환경 기준)  
그렇다면 우리는 함수 호출 과정에서 `vis`배열을 전달하는 것에 걸리는 시간을 줄여야 한다.  
`std::vector<bool>`은 bit단위로 계산되도록 오버로딩 되어 있어서, 복사하는데 시간이 적게 걸릴 것 같다.  
하지만 더 적은 시간을 사용하는 방법이 있다.  
맨 처음에 언급했듯이, 배열은 링크드 리스트보다 전체 순회 시간이 빠르다.  
그 이유는 연속된 메모리 구조를 가졌기 때문이다. (linked list는 node구조로 구현되어 있다)  
마찬가지로, `std::vector<bool>`은 비트의 링크드 리스트와 같다.  
그 이유는 원래 `bool`형은 1비트를 소모하지만, `std::vector<bool>`은 1비트만을 사용하도록 메모리 최적화가 구현되어 있기 때문이다.  
그것은 위의 런타임 데이터에서도 확인할 수 있는데, `std::_Bit_iterator`와 같은 형태가 많이 보일 것이다.  
C++에서의 `iterator`클래스는 자료구조를 순회하는 포인터 역할을 한다.  
포인터를 통해 순회한다는 것은 해당 자료구조가 연속된 메모리 영역에 있지 않다는 것을 의미한다.  
`std::vector<bool>`은 실제로 원소 하나당 메모리를 1비트씩 사용하지만, 4비트 단위로 1비트씩 제이터가 저장된다. (정확히는 비트필드 형태로 구현되어 있음)  
따라서 다른 자료구조를 사용해야 하고, 해당 자료구조는 연속된 비트를 저장해 캐시 히트율을 높여야 한다.  
```cpp
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define X first
#define Y second
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;

const int inf = 1e9;

int h,w,k;
int ans=0;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void inline DFS(const vector<string>& b, pair<int, int> pos, vector<bitset<10>> vis, int d) {
    vis[pos.X][pos.Y] = true;
    if (d == k) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int x = pos.X + dx[i];
        int y = pos.Y + dy[i];
        if (x < 0 || x >= h || y < 0 || y >= w) continue;
        if (b[x][y] == '#' || vis[x][y]) continue;
        DFS(b, {x, y}, vis, d + 1);
    }
}

void Solve()
{
    cin >> h >> w >> k;
    vector<string> b(h);
    for (int i = 0; i < h; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (b[i][j] == '#') continue;
            vector<bitset<10>> vis(h); // `bitset`으로 메모리 사용량 감소
            DFS(b, {i, j}, vis, 0);
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	
    int T=1; //cin>>T;
    while(T--)
    {
        Solve();
    }
    /** 
     * 
    */
    return 0;
}
```
위의 코드는 `std::bitset`자료구조를 사용해 캐시 히트율을 높인 코드이다.  
해당 코드는 147ms로 AC를 받을 수 있다. (atcoder 채점 서버 기준)  
정말로 `vis`배열의 복사 과정에서 시간이 단축되었는지 확인해 보자.  
```
Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
 23.40      0.11     0.11      100     1.10     4.70  DFS(std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > const&, std::pair<int, int>, std::vector<std::bitset<10ul>, std::allocator<std::bitset<10ul> > >, int)
 10.64      0.16     0.05  6577516     0.00     0.00  std::bitset<10ul>* std::__do_uninit_copy<__gnu_cxx::__normal_iterator<std::bitset<10ul> const*, std::vector<std::bitset<10ul>, std::allocator<std::bitset<10ul> > > >, std::bitset<10ul>*>(__gnu_cxx::__normal_iterator<std::bitset<10ul> const*, std::vector<std::bitset<10ul>, std::allocator<std::bitset<10ul> > > >, __gnu_cxx::__normal_iterator<std::bitset<10ul> const*, std::vector<std::bitset<10ul>, std::allocator<std::bitset<10ul> > > >, std::bitset<10ul>*)
  8.51      0.20     0.04 65775160     0.00     0.00  std::bitset<10ul> const& std::forward<std::bitset<10ul> const&>(std::remove_reference<std::bitset<10ul> const&>::type&)
  6.38      0.23     0.03 144705352     0.00     0.00  __gnu_cxx::__normal_iterator<std::bitset<10ul> const*, std::vector<std::bitset<10ul>, std::allocator<std::bitset<10ul> > > >::base() const
  6.38      0.26     0.03 65775160     0.00     0.00  void std::_Construct<std::bitset<10ul>, std::bitset<10ul> const&>(std::bitset<10ul>*, std::bitset<10ul> const&)
  4.26      0.28     0.02 65776160     0.00     0.00  std::bitset<10ul>* std::__addressof<std::bitset<10ul> >(std::bitset<10ul>&)
  4.26      0.30     0.02 33396104     0.00     0.00  std::_Base_bitset<1ul>::_S_whichbit(unsigned long)
  4.26      0.32     0.02 10120536     0.00     0.00  std::bitset<10ul>::reference::operator bool() const
  4.26      0.34     0.02  6577516     0.00     0.00  std::vector<std::bitset<10ul>, std::allocator<std::bitset<10ul> > >::begin() const
  2.13      0.35     0.01 72352676     0.00     0.00  bool __gnu_cxx::operator!=<std::bitset<10ul> const*, std::vector<std::bitset<10ul>, std::allocator<std::bitset<10ul> > > >(__gnu_cxx::__normal_iterator<std::bitset<10ul> const*, std::vector<std::bitset<10ul>, std::allocator<std::bitset<10ul> > > > const&, __gnu_cxx::__normal_iterator<std::bitset<10ul> const*, std::vector<std::bitset<10ul>, std::allocator<std::bitset<10ul> > > > const&)
```
위의 데이터를 보면 원래 데이텅에서 실행 시간이 작은 편이었던 `DFS`함수 자체의 call시간이 가장 오래 걸리게 되었음을 알 수 있다.  
또한 `std::bitset`이 들어간, 즉 `vis`를 복사하는 부분에 걸리는 시간히 현저히 줄어들었음이 보인다. (local 기준 1초 이하)  
`std::bitset`은 크기가 지정된 자료형이다.  
`vis`선언을 보면, `vector<bitset<10>> vis(10)`으로 선언한다.  
`bitset<10>`은, 10비트의 크기를 가진 배열을 선언하겠다는 의미이며, 해당 배열의 메모리는 연속적이다.  
따라서 캐시 히트율이 높으며, 복사/할당/삭제 연산에 있어 높은 효율성과 낮은 런타임을 보인다.  
