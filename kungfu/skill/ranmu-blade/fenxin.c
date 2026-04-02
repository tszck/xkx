// renmu-daofa 燃木刀法

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "「焚心」"
int perform(object me, string arg)
{
	object weapon, target;
	int i, j, z;       
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
/*  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中沒有這種功能。\n");
*/
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不對。\n");

	if (weapon->query("id") != "mu dao" || weapon->query("ownmake"))
		return notify_fail("你沒有木刀，無法使出「焚心」絕技！\n");

	fskill = "yijinjing";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 170 )
		return notify_fail("你的"+to_chinese(fskill)+"修為不夠，無法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 160 )
		return notify_fail("你的"+to_chinese(sskill)+"火候不夠，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(bskill)+"還不夠嫺熟，使不出"+PNAME+"。\n");

	if( (int)me->query_skill("force", 1) < 200 )
		return notify_fail("你的內功等級不夠，使不出「焚心」絕技。\n");

	if( (int)me->query_str() < 32)
		return notify_fail("你的膂力還不夠強勁，使不出「焚心」。\n");
	if( (int)me->query_dex() < 30)
		return notify_fail("你的身法還不夠迅猛，使不出「焚心」。\n");

	if(me->query_temp("ranmu")) 
		return notify_fail("你現在正在使用「焚心」絕技。\n"); 

	if (me->query_temp("fumo"))
		return notify_fail("你現在正在使用「金剛伏魔」神功。\n"); 

	if (me->query("neili") < 1000)
		return notify_fail("你的內力不夠。\n");

	j = me->query_skill("blade", 1)/10;
	z = me->query_skill("force", 1)/10;
	i = me->query_skill("force", 1)/10;
	me->add("neili", -j*8);
	me->add_temp("apply/strength", z);
	me->add_temp("apply/attack", j); 
	me->add_temp("apply/damage", 80);
	me->set_temp("ranmu", 1);
	call_out("check_fight", 1, me, z, j, i);
	message_combatd(HIR "$N"HIR"單掌合揖，突然爆吼一聲，運起佛門至上金剛伏魔功，\n手中的木刀頓時化作一團火焰，激盪的炙流將$n團團圍住！\n"NOR,me,target);
	return 1;
}

void remove_effect(object me, int j, int z, object weapon)
{
	object piece;
	me->add_temp("apply/strength", -z);
	me->add_temp("apply/attack", -j);
	me->add_temp("apply/damage", -80);
	me->delete_temp("ranmu");
	tell_object(me, HIR"你「焚心」絕技運行完畢，氣回丹田");
	if (weapon && weapon->query("id") == "mu dao")
	{
		weapon->unequip();
		seteuid(getuid());
		piece = new("/clone/misc/piece");
		piece->set_name("木頭", ({ "mu tou" }));
		piece->set("unit", "塊");
		piece->set("long","一塊木頭。\n");
		tell_object(me, "，手中的木刀變成了一塊木頭。\n" NOR);
	  piece->move(me);
	  destruct(weapon);
	}
	else tell_object(me, "。\n" NOR);
}

void check_fight(object me, int z, int j, int i)
{
	object weapon;      

	if (!me) return;
	if(!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id") != "mu dao" ||
		weapon->query("skill_type") != "blade")
	{
		remove_effect(me, j, z, weapon);
		return;
	}
	if (i < 1 || !me->is_fighting())
	{
		remove_effect(me, j, z, weapon);
		return;
	}
	call_out("check_fight", 1, me, z, j, i-1);
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
        write(@HELP

        使用功效：
                焚燒手中木刀，大增自身攻擊力

        出手要求：
                燃木刀法160級
                基本刀法140級
                基本內功200級
                易筋經170級
                後天膂力32
                後天身法30
                內力1000
HELP
        );
        return 1;
}

