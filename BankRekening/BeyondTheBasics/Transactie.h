#pragma once

#include <iostream>
#include <chrono>

class Transactie
{
public:
	Transactie(int _transactionValue);
	int ReturnTransactionValue() const;
	std::time_t GetTheTransactionDate() const;

private:
	std::time_t date;
	int transactionValue = 0;
};