typedef struct L {
	
	struct L * l;

	int val;

} L;

int sll_to_int(L * in) {
	
	int ans = 0; int n = 1;

	while ( in != 0 ) {
		
		ans += (in->val) * n;

		n = n * 10;

		in = in->l;
	}

	return ans;
}

L * insert_sll(L ** in, int v) {
	
	while ( (*in)->l != 0 ) {
		
		in = &((*in)->l);

	}

	(*in)->l = (L*)calloc(1,sizeof(L));

	in = &((*in)->l);

	(*in)->val = v;

	return *in;

}

L * int_to_sll(int in) {
	
	L * sll = (L*)calloc(1,sizeof(L));

	L * ans = sll;

	while ( in > 0 ) {
		
		sll = insert_sll(&sll,in%10);

		in /= 10;

	}

	ans = ans->l;

	return ans;
}

L * add_two_numbers(L * I1, L * I2) {
	
	int num1 = sll_to_int(I1);

	int num2 = sll_to_int(I2);

	int ans = num1+num2;

	return int_to_sll(ans);
}

void reverse_print_sll(L * in) {
	
	if (in == 0){return;}

	reverse_print_sll(in->l);

	printf("%d ",in->val);
}

int main(void) {
	
	L * s = (L*)calloc(1,sizeof(L));

	L * s_0 = s;

	s = insert_sll(&s,2);

	s = insert_sll(&s,4);

	s = insert_sll(&s,3);

	s = s_0->l;

	reverse_print_sll(s);

	putchar(0xa);
	
	printf("%d\n",sll_to_int(s));
	
	putchar(0xa);

	L * t = (L*)calloc(1,sizeof(L));

	L * t_0 = t;

	t = insert_sll(&t,5);

	t = insert_sll(&t,6);

	t = insert_sll(&t,4);

	t = t_0->l;

	reverse_print_sll(t);

	putchar(0xa);

	printf("%d\n",sll_to_int(t));
	
	s_0 = int_to_sll(sll_to_int(s));
	
	reverse_print_sll(s_0);

	putchar(0xa);

	L * r = add_two_numbers(t,s);
	
	reverse_print_sll(r);
	
	return 0;
}
