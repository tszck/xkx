inherit F_CLEAN_UP;

int main(object me, string arg)
{
  return notify_fail("你要在掌門師尊面前才能切磋。\n");
}
int help(object me)
{
write(@help
 指令格式 : qiecuo <基本功>[.<絕招名>]

    俠客行的武功很多都有絕招，但第一次使用這些絕招前，你必須找到門
派的掌門人，向掌門人切磋過才能用，如：qiecuo force.powerup  你需要
足夠的的門派忠誠度才可以向掌門人切磋武學。前三次切磋需要的忠誠度分
別為100點、400點、900點，之後需要的忠誠度固定為1600點。最早的忠誠
度可以在武館詢問陳有德，並與武館內的本門弟子探討武功來獲取，之後可
以通過做三個本門任務來提高。

    連續完成一定次數的本門叛徒任務後，掌門師尊會給你一次向他切磋特
殊武功的機會，你可以用qiecuo * 指定某項基本技能，如 qiecuo parry
這項基本技能相應的特殊技能會得到提高！
help
);
 return 1;
}