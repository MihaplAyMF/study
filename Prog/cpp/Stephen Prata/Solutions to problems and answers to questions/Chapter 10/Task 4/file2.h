#pragma once

namespace SALES
{
	const int QUARTERS = 4;
	class Sales
	{
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	public:	
		Sales();
		Sales(double sales[QUARTERS]);
		void setSales(const double ar[], int n);
		void setSales();
		void showSales() const;
	};


}