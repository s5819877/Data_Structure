이 ADT는 정수형 분자와 분모로 이루어진 분수 자료형을 정의한다.  
분수는 사칙연산을 지원하며, 결과는 기약분수 형태로 반환된다.  
추가로 분수 외의 소수나 정수도 입력 가능하다.  

- 변환 및 출력  
Fraction create_from_string(char* str); // 문자열을 분수로 변환  
Fraction simplify(Fraction f); // 기약분수화  
void print_fraction(Fraction f); // 분수 출력  

- 사칙연산  
Fraction add(Fraction f1, Fraction f2); // 덧셈  
Fraction sub(Fraction f1, Fraction f2); // 뺄셈  
Fraction mul(Fraction f1, Fraction f2); // 곱셈  
Fraction div_frac(Fraction f1, Fraction f2); // 나눗셈  