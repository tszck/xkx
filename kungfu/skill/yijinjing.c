// yijinjing.c 少林 易筋經神功
// Last Modified by sega on Mar. 10 2000
// Feb.21 1998 by Java

#include <ansi.h>
inherit FORCE;
#include "force.h"
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	mapping skl = me->query_skills();
	string *sk;
	string skl_name = explode(__FILE__, "/")[<1][0..<3];
	int i, nb, nf, oh, oh1, nh, ns, ts;
	nb = (int)me->query_skill("buddhism", 1);
	nf = (int)me->query_skill("force", 1);
	oh = (int)me->query_skill("hunyuan-yiqi", 1);
	oh1 = (int)me->query_skill("zhanzhuang-gong", 1);
	nh = (int)me->query_skill("yijinjing", 1);
	ns = (int)me->query("guilty");

	if ( oh + oh1 < 100 )
		return notify_fail("你的少林內功太低，無法學習易筋經神功！\n");
	if ( me->query("couple/have_couple") )
		return notify_fail("你塵緣未了，無法再學習易筋經神功！\n");
	if ( me->query("sex/number") )
		return notify_fail("你已經破了色戒，無法再學習易筋經神功！\n");
	if ( me->query("gender") != "男性" )
		return notify_fail("你非童男之體，不能練習易筋經神功。\n");

	if ( nb < 100 && nb <= nh )
		return notify_fail("你的禪宗心法修為不夠，無法領會更高深的易筋經神功。\n");

	if ( nf < 10)
		return notify_fail("你的基本內功火候還不夠，無法領會易筋經神功。\n");

	if ( ns > 0 ) 
		return notify_fail("你屢犯僧家數戒，無法領會更高深的易筋經神功。\n");

	return valid_public(me,({"zhanzhuang-gong","hunyuan-yiqi"}));
}

int practice_skill(object me)
{
	return notify_fail("易筋經神功只能用學(learn)的來增加熟練度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"yijinjing/" + func;
}

//add by sega
mixed be_hit_ob(object me,object victim,int damage_bonus,int factor)

//factor= 加力 damage_bonus=臂力 .
{
	int ap,dp;
//內功相差太多(至少2倍以上),內力傷害全部抵消,基本上不出現
	ap=me->query_skill("force");
	dp=victim->query_skill("force");
	if ((int)random(ap/2)>dp && me->query("neili")>2000)
	{

		if (random(10)==1) tell_object(victim, "你只覺得如同擊在金屬上，頭腦裏閃過一個念頭：金屬罩！\n");
		else tell_object(victim,HIY"你只覺得勁力如同擊在金屬罩，根本無法傷他分毫！\n"NOR);
		tell_object(me, HIY"你只覺得勁力襲體，急忙運起金鐘罩神功，一股真氣瀰漫全身！\n"NOR);
		me->add("neili",-2*damage_bonus);
		return -damage_bonus;
	}
	else if ((random(ap*2)>dp) && me->query("neili")>1500)
	{
		if (random(10)==1) tell_object(victim,HIY"你只覺得如同擊在金屬上，頭腦裏閃過一個念頭：“金屬罩”！\n"NOR);
		else tell_object(victim,HIY"你只覺得勁力如同擊在金屬上，虎口隱隱作痛！\n"NOR);
		tell_object(me, HIY"你只覺得勁力襲體，勉力運起金鐘罩，一股真氣瀰漫全身！\n"NOR);
		me->add("neili",-damage_bonus);
		return -random(damage_bonus);
	}
	return 0;
}

int help(object me)
{
	write(HIC"\n易筋經神功："NOR"\n");
	write(@HELP

    《易筋》，《洗髓》二經向為少林鎮寺之寶，相傳為達摩祖師
所創，載有不少天竺高僧的瑜伽祕術，但由於其習練艱難，須得勘
破“我相，人相”，心中不存修習武功之念，故歷代弟子罕有練成
者。
    《洗髓》記載天下所有武功的精要，《易筋》則是一門極其高
深的內功心法書籍。

	學習要求：
		未破色戒的童男之身
		未犯戒
		混元一氣功100級
		相應級別的禪宗心法
HELP
	);
	return 1;
}

