#include "OrderComposite.h"
#include "OrderItem.h"
#include "Modifier.h"
#include "ConcreteOrderBuilder.h"
#include "OrderBuilder.h"
#include "../customer/Customer.h"

int doCheck(){
       Customer c1 = Customer("c1", 0.85);
       ConcreteOrderBuilder * ob = new ConcreteOrderBuilder();
       c1.buildOrder(*ob);
}