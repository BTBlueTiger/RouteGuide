#include "include/navigation/NavigationManager.h"



void  NavigationManager::changePage(const QString &page)
{
    emit goToPage(page);
}


