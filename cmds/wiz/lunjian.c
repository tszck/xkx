inherit F_CLEAN_UP;

int main(object me,string arg)
{
  int level=-1;
	if (!wizardp(me))
	  return 0;
	if (arg=="少俠試劍" || arg=="1") 
	  level=0;
	else if (arg=="名俠比劍"|| arg=="2") 
	  level=1;
	else if (arg=="大俠評劍"|| arg=="3") 
	  level=2;
	else if (arg=="宗師論劍"|| arg=="4") 
	  level=3;
	else 
	  return notify_fail("只能指定 少俠試劍(1)、名俠比劍(2)、大俠評劍(3)、宗師論劍(4) 中的一個。\n");
	return PK_D->start_by_others(level);
}
int help(string arg)
{
write(@help
lunjian <指定的比賽>

該命令用於巫師手動開啓華山論劍。
目前可以指定的比賽有：少俠試劍(1)、名俠比劍(2)、大俠評劍(3)、宗師論劍(4)。
help
);
return 1;
}