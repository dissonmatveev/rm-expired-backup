#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
/****************************************************************************************************
1. добавить функцию check_backups_dates
2. исключить опции которые не понадобятся
3. добавить опцию --check_backups, которая проверяет количество бекапов, их даты.
4. инкременты создавать с порядковым числом в имени(чтобы можно было восстанавливать по порядку).
5.

Хранить:

1. полный бекап с имением типа date-full
2. инкремент с именем date-increment-1, date-increment-2,... то есть с порядковым номером инкремента.
3. количество инкрементов = максимальному количеству дней хранения. для надежности нужно иметь два полных бекапа и , наверно, 14 дней для инкрементов.

Проверка:

1.Если количество инкрементальных бекапов равно 7 и существует только один полный - создать еще один полный.
2. если количество инкрементов 14 и есть два полных - удалить первый полный и все его инктерменты
3. в других случаях находить последний полный бекап и создавать инкременты к нему
4. можно добавить в логику два варианта проверки - с двумя полными и с одним полным бекапом.
-c check
-r remove backups


Реализация.

1. добавить опции в getopt(или как там реализовано)
2. Макросами захардкодить кол-во инкрементов, количество полных бекапов и проч
3. Считать содержимое каталога с бекапами, поместить в структуру и сортировать делать другие действия. 

Важно создавать имена каталогов именно с такими именами.
prepare делать автоматически?

**********************************************************************************************************/
#define FULLBACKUPS 2 // number of full backup
#define INCRBACKUPS 14 // number of incremental backups
int main(int agrc, char ** argv)
{

    char *help_message;
    char oc;
    help_message="Usage: %s [-c check backups]\n"
                 "          [-r remove expired backups]\n";

    while((oc=getopt(argc, argv, ":c:r:")) != -1)
    {
        switch (oc)
        {
          case  '?':
              fprintf(stderr, help_message, argv[0]);
              exit(1);

          case 'r':
          
          case 'c':

          default:
              fprintf(stderr,%s,help_message);
              exit(2);
        }
    }
