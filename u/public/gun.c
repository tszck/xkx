// gun.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void init()
{
        add_action("do_aim","aim");
        add_action("do_shoot","shoot");
}

void create()
{
	set_name("金手槍", ({ "shou qiang", "qiang", "gun" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("bullet", 10);
		set("value", 50000);
		set("material", "steel");
		set("long", "這是一把零零七用過的金手槍，裏面滿裝着十發黃金子
彈。先瞄準(aim)某人，再射擊(shoot)！\n");
		set("wield_msg", "$N從腰邊的槍套裏掏出一把$n握在手中。\n");
		set("unequip_msg", "$N將手中的$n插回腰間的槍套裏。\n");
	}
	init_blade(100);
	setup();
}

int do_aim(string arg)
{
	object me, obj;
	
	me = this_player();

	if( !arg )
		return notify_fail("你想殺誰？\n");

	if( this_object()->query("bullet") <=0)
		return notify_fail("金子彈已經打光了。\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("這裏沒有這個人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一點，那並不是活物。\n");

	if(obj == me)
		return notify_fail("用 suicide 指令會比較快:P。\n");

	message_vision(HIY "\n$N舉起金手槍，遠遠地瞄準$n，接着「克」地一聲，把子彈壓上了膛。\n\n" NOR, 
			me, obj);

	this_object()->set_temp("target", arg);

	return 1;
}

int do_shoot()
{
	object me, obj;
	string arg;

	me = this_player();

	if( !(arg = this_object()->query_temp("target")) ) 
		return notify_fail("你還沒有瞄準你的射擊目標！\n");

	if( !objectp(obj = present(arg, environment(me)) ))
		return notify_fail("你要射擊的對象已經離開了。\n");

	message_vision(HIR "\n$N對準$n扣動了扳機！！！\n只聽「乒」地一聲巨響，$n慘叫一聲，緩緩地仆倒在血泊裏！\n\n" NOR,
			me, obj);

	this_object()->add("bullet", -1);
	obj->die();

	return 1;
}

