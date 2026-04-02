// douzhuan-xingyi.c 鬥轉星移
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *parry_msg = ({
	YEL"驀地裏一股力道飛來，將$n一引一帶，$n身子輕輕越起，身行落在一旁。\n"NOR,
	BLU"$n當下一股內力衝向$l，$N擊向$n的$l的招數莫名奇妙的溜滑向一旁。\n"NOR,
	HIW"$n雙手前探，左臂搭上$N右臂，右臂使出$N的招數將$N此招化去。\n"NOR,
	HIY"$n星移鬥轉，$N這招莫名其妙的在中途轉了方向，直奔自己襲來。\n"NOR,
	YEL"$n作壁上觀，雙手與對方相交數掌，談笑間竟使出$N成名技藝，使得$N不知如何是好。\n"NOR,
	BLU"$n凝神運氣向$N猛攻快打，使出的招數好似$N的成名絕技，把$N的招數化於無行。\n"NOR,
	HIW"只見$n身如飄風，恰似漫天星移，詭異地一式，雙掌動向無定不可捉摸地拍向$N的$l。\n"NOR,
	HIY"$n身行飄忽不定，在星移鬥轉之間反用$N的招數擊向$N，卻令人$N百思不得其解。\n"NOR,
	HIY"$n輕輕一帶，$N發現自己招數回擊過來，嚇得往後倒退幾步。\n"NOR,
	HIY"$n手臂迴轉，在$N手肘下輕輕一推，$N招數落空。\n"NOR,
	HIY"$n右手伸出，在$N手腕上輕輕一拉，$N收勢不住，直往前撲去。\n"NOR,
	HIY"$n雙手迴圈，$N只覺得前面好象有一堵牆，再也攻不進去。\n"NOR,
});

int valid_enable(string usage) { return usage=="parry"; }
string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}
int valid_learn(object me)
{
	object ob;
	int d_lvl = (int) me->query_skill("douzhuan-xingyi",1);
	int s_lvl = (int) me->query_skill("shenyuan-gong",1);
	int l_lvl = (int) me->query_skill("literate",1);

	mapping myfam;
	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "姑蘇慕容" ||
		myfam["master_id"] != "murong fu")
		return notify_fail("鬥轉星移只有嚮慕容公子學習。\n");
	if( (int)me->query("betrayer") > 0 )
		return notify_fail("你曾背叛師門，心志不純，沒有辦法練鬥轉星移。\n");
	if( (int)me->query_int() < 40 )
		return notify_fail("你仔細地想了一會，還是沒明白借力用力的道理。\n");
 	if( (int)me->query("max_neili") < 600 )
		return notify_fail("你的內力不夠，沒有辦法練鬥轉星移。\n");
	if( s_lvl < 100)
		return notify_fail("鬥轉星移必須先學好神元功才能練習。\n");
	if( s_lvl + 30 < d_lvl)
		return notify_fail("你的神元功級別不夠你真正領會更高級的鬥轉星移。\n");
	if( l_lvl + 50 < d_lvl)
		return notify_fail("你的讀書寫字水平不夠你領會更高級的鬥轉星移。\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("鬥轉星移只能通過學習來提高。\n");
}
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"douzhuan-xingyi/" + action;
}
int help(object me)
{
	write(HIC"\n鬥轉星移："NOR"\n");
	write(@HELP

    姑蘇慕容家最拿手的絕技，乃是一門借力打力之技，叫做“鬥
轉星移”。外人不知底細，見到慕容氏“以彼之道，還施彼身”神
乎其技，凡在致人死命之時，總是以對方的成名絕技加諸其身，顯
然天下各門各派的絕技，姑蘇慕容氏無一不會，無一不精。其實武
林中絕技千千萬萬，任他如何聰明淵博，決難將每一項絕技都學會
了，何況既是絕技，自非朝夕之功所能練成。但慕容氏有了這一門
巧妙無比的“鬥轉星移”之術，不論對方施出何種功夫來，都能將
之轉移力道，反擊到對方自身。出手的人武功越高，死法就越是巧
妙。慕容氏若非單打獨鬥，若不是有把握定能致敵死命，這“鬥轉
星移”的功夫便決不使用，是以姑蘇慕容氏名震江湖，真正的功夫
所在，卻是誰也不知。將對手的兵刃拳腳轉換方向，令對手自作自
受，其中道理，全在“反彈”兩字。便如有人一拳打在石牆之上，
出手越重，拳頭上所受的力道越大，輕重強弱，不差分毫。只不過
轉換有形的兵刃拳腳尚易，轉換無形無質的內力氣功，那就極難。

	學習要求：
                不叛師
                慕容復的嫡傳弟子
		後天悟性40
		神元功100級
		神元功不能低於鬥轉星移30級
		讀書寫字不能低於鬥轉星移50級
		內力600
HELP
	);
	return 1;
}

