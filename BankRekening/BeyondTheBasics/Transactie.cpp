#include "Transactie.h"

Transactie::Transactie(int _transactionValue)
{
	transactionValue = _transactionValue;

	auto local = std::chrono::zoned_time{ std::chrono::current_zone(), std::chrono::system_clock::now() };
	date = std::chrono::system_clock::to_time_t(local);
}

int Transactie::ReturnTransactionValue() const
{
	return transactionValue;
}

std::time_t Transactie::GetTheTransactionDate() const
{
	return date;
}
