#pragma once
#include <vector>
#include "Transactie.h"
#include <queue>
#include <iostream>
#include <ctime>
#include <time.h>

class Bankrekening
{
public:
	int ReturnBankValue() const;
	Bankrekening operator+(const Transactie& transaction) const;
	friend std::ostream& operator<<(std::ostream& os, const Bankrekening& config);
	std::vector<Transactie> ReturnTransactionHistory() const;

private:
	int bankValue = 0;
	std::vector<Transactie> transactionHistory;
};