## Optimization
- 32230250 권민성

### 캐시 히트를 통한 시간 단축<br>
   https://github.com/minsung-kwon/SystemProgramming/blob/TimeCheck/CacheHit.md
   <br><br>
### unrolling roop를 통한 시간 단축<br>
   https://github.com/minsung-kwon/SystemProgramming/blob/TimeCheck/Unrolling%20Roop%20%26%20Cutting.md
   <br><br>

### 환경 구축
> WSL Ubuntu 24.04 LTS - C++ 23 gdb  
> 컴파일 옵션 : `g++ -pg -o program program.cpp`  
> `input.txt`에 테스트 데이터를 입력 후, `./program<input.txt`로 실행 파일 실행  
> `gprof program gmon.out > timedata.txt`로 `timedata.txt`에 런타임 분석 테이터 저장  
- 데이터 예시
```text
Flat profile:

Each sample counts as 0.01 seconds.
 no time accumulated

  %   cumulative   self              self     total           
 time   seconds   seconds    calls  Ts/call  Ts/call  name    
  0.00      0.00     0.00  1828026     0.00     0.00  std::vector<int, std::allocator<int> >::operator[](unsigned long)
  0.00      0.00     0.00  1542045     0.00     0.00  std::remove_reference<int&>::type&& std::move<int&>(int&)
  0.00      0.00     0.00   514015     0.00     0.00  std::enable_if<std::__and_<std::__not_<std::__is_tuple_like<int> >, std::is_move_constructible<int>, std::is_move_assignable<int> >::value, void>::type std::swap<int>(int&, int&)
  0.00      0.00     0.00        1     0.00     0.00  Solve()
  0.00      0.00     0.00        1     0.00     0.00  std::_Vector_base<int, std::allocator<int> >::_M_allocate(unsigned long)
  0.00      0.00     0.00        1     0.00     0.00  std::_Vector_base<int, std::allocator<int> >::_Vector_impl::_Vector_impl(std::allocator<int> const&)
  0.00      0.00     0.00        1     0.00     0.00  std::_Vector_base<int, std::allocator<int> >::_Vector_impl::~_Vector_impl()
  0.00      0.00     0.00        1     0.00     0.00  std::_Vector_base<int, std::allocator<int> >::_M_deallocate(int*, unsigned long)
  0.00      0.00     0.00        1     0.00     0.00  std::_Vector_base<int, std::allocator<int> >::_M_create_storage(unsigned long)
  0.00      0.00     0.00        1     0.00     0.00  std::_Vector_base<int, std::allocator<int> >::_Vector_impl_data::_Vector_impl_data()
  0.00      0.00     0.00        1     0.00     0.00  std::_Vector_base<int, std::allocator<int> >::_M_get_Tp_allocator()
  0.00      0.00     0.00        1     0.00     0.00  std::_Vector_base<int, std::allocator<int> >::_Vector_base(unsigned long, std::allocator<int> const&)
  0.00      0.00     0.00        1     0.00     0.00  std::_Vector_base<int, std::allocator<int> >::~_Vector_base()
  0.00      0.00     0.00        1     0.00     0.00  std::__new_allocator<int>::deallocate(int*, unsigned long)
  0.00      0.00     0.00        1     0.00     0.00  std::__new_allocator<int>::allocate(unsigned long, void const*)
  0.00      0.00     0.00        1     0.00     0.00  int* std::__uninitialized_default_n_1<true>::__uninit_default_n<int*, unsigned long>(int*, unsigned long)
  0.00      0.00     0.00        1     0.00     0.00  std::vector<int, std::allocator<int> >::_S_max_size(std::allocator<int> const&)
  0.00      0.00     0.00        1     0.00     0.00  std::vector<int, std::allocator<int> >::_S_check_init_len(unsigned long, std::allocator<int> const&)
  0.00      0.00     0.00        1     0.00     0.00  std::vector<int, std::allocator<int> >::_M_default_initialize(unsigned long)
  0.00      0.00     0.00        1     0.00     0.00  std::vector<int, std::allocator<int> >::vector(unsigned long, std::allocator<int> const&)
  0.00      0.00     0.00        1     0.00     0.00  std::vector<int, std::allocator<int> >::~vector()
  0.00      0.00     0.00        1     0.00     0.00  void std::_Construct<int>(int*)
```
<br><br>
### 참고 문헌
https://en.cppreference.com/w/cpp/container/vector_bool  
https://en.cppreference.com/w/cpp/utility/bitset  
