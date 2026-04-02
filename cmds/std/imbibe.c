// Filename : /cmds/std/imbibe.c
// Last Modified by winder on Aug. 5 2001
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object *obj, pet;
//	string owner;
	int i, j, lvl;

	seteuid(getuid());

	if(!arg || arg == " ")
		return notify_fail("你要給誰喂水？\n");
	if(!objectp(pet = present(arg, environment(me))) || !living(pet))
		return notify_fail("這裏沒有這動物。\n");
	if(pet->query("race") == "人類" )
		return notify_fail(pet->name()+"是寵物麼？瞪大眼睛看看！\n");
	if(pet->is_busy() )
		return notify_fail(pet->name()+"正忙着呢，哪喝得下什麼！\n");
	if(me->is_busy() )
		return notify_fail("你正忙着呢，什麼也做不了！\n");
	if(pet->is_fighting() )
		return notify_fail("你沒看道它正在打架嗎？！\n");
	if(me->is_fighting() )
		return notify_fail("一邊打架一邊喂水？你真是活膩了！\n");
	if((string)me->query("id")!=(string)pet->query_temp("owner"))
		return notify_fail("你不是"+pet->query("name")+"的主人，人家不會理你的。\n");
	if(pet->query("water") >= pet->max_water_capacity() )
		return notify_fail(pet->name()+"已經喝得太多了，再也灌不下任何東西了。\n");

	me->start_busy(1);
	if(environment(me)->query("resource/water") )
	{
		if((string)pet->query("drink_msg"))
			message_vision(pet->query("drink_msg"), pet);
		else message_vision("$N伸長舌頭舔了舔水面，一仰脖頸，喝了下去。\n", pet);
		pet->add("water", 30);
	}
	else
	{
		obj = all_inventory(environment(me));
		for (i = 0; i < sizeof(obj); i++)
		{
			if(obj[i]->query("liquid/remaining") )
			{
				break;
			}
		}
		if( i == sizeof(obj) )
			return notify_fail("這裏沒啥東西可以給"+pet->name()+"喂水。\n");
// 寵物飲水狀態改變。
		pet->add("water", 10+obj[i]->query("liquid/drunk_apply"));
// 容器容量改變。
		obj[i]->add("liquid/remaining", -1);
// 喫的不busy，喂的busy，feed.c也一樣。
		if((int)obj[i]->query("liquid/busy"))
			me->start_busy(obj[i]->query("liquid/busy"));
		if(obj[i]->query("liquid/remaining"))
			message_vision("$N伸長脖頸對着$n，唏唏嗦嗦地喝了幾口"+obj[i]->query("liquid/name")+"。\n", pet, obj[i]);
		else
			message_vision("$N伸長脖頸對着$n，唏唏嗦嗦就把"+obj[i]->query("liquid/name")+"喝了個精光。\n", pet, obj[i]);
// 喝到毒藥啦。
		if( obj[i]->query("liquid/poisontime") > 1 )
		{
			pet->apply_condition(obj[i]->query("liquid/poison"), obj->query("liquid/poisontime") );
			write(pet->query("name")+"突然覺得很難受地扭着腰掙扎了兩下，好象喝的東西有點不對勁。\n");
		}
// 喝到酒啦。
		switch(obj[i]->query("liquid/type"))
		{
			case "alcohol": pet->apply_condition("drunk",(int)pet->query_condition("drunk")+ (int)obj[i]->query("liquid/drunk_apply"));
					break;
		}
	}

// 寵物升級，與馴獸無關。
	if(pet->query("owner") == me->query("id")) 
	{
// 食物作用改變，累計以便升級。
		pet->add("feed", 1);
		i = pet->query("feed");
		j = pet->query("level");
		if(i>=2+j*j)
		{
			tell_object(me,HIY"你餵了這一次飲水後，發覺"+pet->query("name")+"似乎更聽話了！\n"NOR);
// 餵養長級別。
			pet->add("level",1);
			pet->set("feed",0);
// 餵養長馴服度。
			pet->add("obe", 1);
			lvl=pet->query("level");
		}
		pet->add("max_qi", lvl);
		pet->add("max_jing", lvl);
	}

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : imbibe <動物>

    此指令可用於餵養你所馴服的動物。

    對於已經馴服的動物，可以進行下述指令：

基本指令：
        come <動物名>:                  讓動物跟隨主人行動。
        stay:                           停止動物的跟隨狀態。
        attack <某物>:                  讓動物攻擊敵人。
        stop <動物名>:                  讓動物停止對人的攻擊。
        release:                        結束主奴狀態，將動物放離。

特殊指令：（只對某些動物適用）
        ride <動物名>:                  騎，如騎馬，虎，雕，鯊等。
        unride <動物名>:                下，離開坐騎。
        feed <飼料> to <動物名>:        替動物餵食。
        imbibe <動物名>:                給動物飲水。

HELP
	);
	return 1;
}
