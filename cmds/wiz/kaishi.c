// Last Modified by winder on Apr. 25 2001
// 手工觸發浩劫

inherit F_CLEAN_UP;

int main(object me, string arg)
{
  if (!arg || arg=="1" || arg=="少林")
  AUTOSAVE_D->haojie();
  else if (arg=="2" || arg=="武當")
  DISASTER_D->disaster(1);
  else if (arg=="3" || arg=="峨嵋")
  DISASTER_D->disaster(2);
  else if (arg=="4" || arg=="華山")
  DISASTER_D->disaster(3);
  else if (arg=="5" || arg=="全真")
  DISASTER_D->disaster(4);
  else if (arg=="6" || arg=="逍遙")
  DISASTER_D->disaster(5);
  else if (arg=="7" || arg=="明教")
  DISASTER_D->disaster(6);
  else if (arg=="8" || arg=="北京")
  DISASTER_D->disaster(7);
  else return notify_fail("你只能選擇"+   
  "少林(1)、武當(2)、峨嵋(3)、華山(4)、全真(5)、逍遙(6)、明教(7)、北京(8)其中一個\n");
  return 1;
}
int help()
{
write(@help
kaishi [指定的門派]

本命令用來提供巫師手動啓動浩劫。
目前支持的門派有：
少林(1)、武當(2)、峨嵋(3)、華山(4)、全真(5)、逍遙(6)、明教(7)、北京(8)
help
);
  return 1;
}