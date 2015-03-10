/** \file Исходный код.cpp*/

#include <iostream>
#include <ctime>
using namespace std;

int fe, la;
/** Funkciya sortirovki elementov */
void fastsort(int *a, int fe, int la)
{
	int sr, m;
	int f=fe, l=la;
	sr=a[(f+l) / 2]; 
	do
	{
		while (a[f]<sr)
			f++;
		while (a[l]>sr)
			l--;
		if (f<=l) /**Kod sortirovki elementov*/
		{
			m=a[f];
			a[f]=a[l];
			a[l]=m;
			f++;
			l--;
		}
	}
	while (f<l);
	if (fe<l) fastsort(a, fe, l);
	if (f<la) fastsort(a, f, la);
}
/** \void main*/
void main()
{
	int n;
	cout<<"Enter the number of elements:\n";
	cin>>n;/**Vvodim kolichestvo elementov*/
	int *q=new int[n];
	cout<<"Enter the elements:\n";
	for (int i=0; i<n; i++)
		cin>>q[i];/**Vvodim elementi*/
	srand(time(NULL));

	fe=0; la=n-1;
	fastsort(q, fe, la);	
	cout<<endl<<"Result fastsort: ";/**Vivodim otsortirovanniy ryad elementovs*/
	for (int i=0; i<n; i++) 
		cout<<q[i]<<" ";
	delete []q;
	system("pause>>void");
}