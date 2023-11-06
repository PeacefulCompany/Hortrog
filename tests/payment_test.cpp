#include "billing/Payment.h"
#include "billing/CashPayment.h"
#include "billing/CardPayment.h"
#include <gtest/gtest.h>


TEST(Payment, getAmt) {
    Payment* payment=new Payment(1,85.0);
    ASSERT_EQ(payment->getAmountOfPayment(), 85.0);
    delete payment;
}

TEST(Payment, getTbl) {
    Payment* payment=new Payment(1,85.0);
    ASSERT_EQ(payment->gettableId(), 1);
    delete payment;
}

TEST(Payment, copyConstructor) {
    Payment* payment=new Payment(1,85.0);
    Payment* copy=new Payment(payment);
    ASSERT_EQ(copy->getAmountOfPayment(), 85.0);
    ASSERT_EQ(copy->gettableId(), 1);
    delete copy;
    delete payment;
}

TEST(Payment, getCashPaid) {
    Payment* payment=new Payment(1,85.0);
    CashPayment* cPayment=new CashPayment(payment,50.0);
    ASSERT_EQ(cPayment->getCashPaid(), 50.0);
    delete cPayment;
    delete payment;
}

TEST(Payment, getCardPaid) {
    Payment* payment=new Payment(1,85.0);
    CardPayment* cPayment=new CardPayment(payment,50.0,"KGovender","04/08/03","1234");
    ASSERT_EQ(cPayment->getCardPaid(), 50.0);
    delete cPayment;
    delete payment;
}

TEST(Payment, getNameOnCard) {
    Payment* payment=new Payment(1,85.0);
    CardPayment* cPayment=new CardPayment(payment,50.0,"KGovender","04/08/03","1234");
    ASSERT_EQ(cPayment->getNameOnCard(), "KGovender");
    delete cPayment;
    delete payment;
}

TEST(Payment, getExpirationDate) {
    Payment* payment=new Payment(1,85.0);
    CardPayment* cPayment=new CardPayment(payment,50.0,"KGovender","04/08/03","1234");
    ASSERT_EQ(cPayment->getExpirationDate(), "04/08/03");
    delete cPayment;
    delete payment;
}

TEST(Payment, getCreditCardNumber) {
    Payment* payment=new Payment(1,85.0);
    CardPayment* cPayment=new CardPayment(payment,50.0,"KGovender","04/08/03","1234");
    ASSERT_EQ(cPayment->getCreditCardNumber(), "1234");
    delete cPayment;
    delete payment;
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}