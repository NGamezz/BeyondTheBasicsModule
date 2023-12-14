#include "Bankrekening.h"

int Bankrekening::ReturnBankValue() const
{
	return bankValue;
}

Bankrekening Bankrekening::operator+(const Transactie& transaction) const
{
	Bankrekening bankAccount;
	bankAccount.bankValue = bankValue + transaction.ReturnTransactionValue();

	for (int i = 0; i < transactionHistory.size(); i++)
	{
		bankAccount.transactionHistory.push_back(transactionHistory[i]);
	}
	bankAccount.transactionHistory.push_back(transaction);
	return bankAccount;
}

std::ostream& operator<<(std::ostream& os, const Bankrekening& bankAccount) {

	os << "Bank Saldo : " << bankAccount.ReturnBankValue() << " Euro." << std::endl;

	auto transactionHistory = bankAccount.ReturnTransactionHistory();

	int count = 0;
	for (auto& transaction : transactionHistory)
	{
		auto transactionValue = transaction.GetTheTransactionDate();

		struct tm bufferResult;
		localtime_s(&bufferResult, &transactionValue);

		os << "Transaction Value = " << transaction.ReturnTransactionValue() << ". Transaction Index = "
			<< count << ". Transaction Date = " << std::put_time(&bufferResult, "%c %Z") << std::endl;
		count++;
	}

	return os;
}

std::vector<Transactie> Bankrekening::ReturnTransactionHistory() const
{
	return transactionHistory;
}