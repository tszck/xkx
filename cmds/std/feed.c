// Filename : /cmds/std/feed.c
// Last Modified by winder on Aug. 5 2001
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object obj, pet;
	string /*owner,*/ food, ob;
	int i, j, lvl/*, effect*/;

	seteuid(getuid());

	if(!arg || sscanf(arg, "%s to %s", food, ob) !=2)
		return notify_fail("你要喂什麼東西給誰？\n");
	if(!objectp(obj = present(food, me)) ) 
		return notify_fail("你身上沒有這樣東西啊。\n");
	if(!objectp(pet = present(ob, environment(me))) || !living(pet))
		return notify_fail("這裏沒有這樣的動物。\n");
	if(pet->query("race") == "人類" )
		return notify_fail(pet->name()+"是寵物麼？瞪大眼睛看看！\n");
	if(pet->is_busy() )
		return notify_fail(pet->name()+"正忙着呢，哪喫得下什麼！\n");
	if(pet->is_busy() )
		return notify_fail(pet->name()+"正忙着呢，哪喫得下什麼！\n");
	if(me->is_busy() )
		return notify_fail("你正忙着呢，什麼也做不了！\n");
	if(pet->is_fighting() )
		return notify_fail("它正在打架呢，你難道沒看見？！\n");
	if(me->is_fighting() )
		return notify_fail("一邊打架一邊餵食？你真是活膩了！\n");
	if(!wizardp(me) && pet->query_temp("feeded"))
		return notify_fail("人一次不能多喫東西，喫多了會拉肚子，"+pet->query("name")+"也一樣。\n");
	if((string)me->query("id")!=(string)pet->query_temp("owner"))
		return notify_fail("你看到"+pet->query("name")+"上前聞了兩下，結果一腳踢開了。\n");
	if(!obj->query("siliao_supply") )
		return notify_fail("似乎"+pet->query("name")+"對這樣東西興趣不大。\n");
	if(!obj->query("siliao_remaining") )
		return notify_fail( obj->name() + "已經沒什麼好喫的了。\n");
	if(pet->query("food") >= pet->max_food_capacity() )
		return notify_fail(pet->name()+"已經喫太飽了，再也塞不下任何東西了。\n");
	obj->set("value", 0);
	obj->add("siliao_remaining", -1);
	me->start_busy(1);
// 寵物食物狀態改變。
	pet->add("food", obj->query("siliao_supply"));
// 延時進食，不能連續喫。剛喫完也不能讓寵物退出。連續機器人喂76天達到100級。
// 9天可以達到50級。
	pet->set_temp("feeded","1");
	call_out("del", 20, pet);
// 寵物升級，與馴獸無關。
	if(pet->query("owner") == me->query("id")) 
	{
// 食物作用改變，累計以便升級。
		if(obj->query("siliao_effect"))
			pet->add("feed", obj->query("siliao_effect"));
// 餵養長經驗。
		pet->add("combat_exp", 5+random(10));
		i = pet->query("feed");
		j = pet->query("level");
		if(i>=2+j*j)
		{
			tell_object(me, HIY"你餵了這一次食物後，發覺"+pet->query("name")+"似乎顯得更強健、也更聽話了！\n"NOR);
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
	if( !obj->query("siliao_remaining") )
	{
		obj->delete_temp("apply/long");
		if((string)obj->query("finish_msg"))
			message_vision(obj->query("finish_msg"), pet, obj);
		else
		{
			message_vision( "$N拿出一"+obj->query("unit")+obj->query("name")+"來，向$n招了招手。\n$n很馴順的走了過去，一把叼起了"+obj->query("name")+"，喫了個乾乾淨淨。\n", me, pet);
		}
		if( !obj->finish_eat() ) destruct(obj);
	} 
	else
	{
		if((string)obj->query("eat_msg"))
			message_vision(obj->query("eat_msg"), pet, obj);
		else 
			message_vision( "$N拿出一"+obj->query("unit")+obj->query("name")+"來，向$n招了招手。\n$n很馴順的走了過去，一把叼起了"+obj->query("name")+"，狠狠就是一口。\n", me, pet);
	}
	if( !obj ) return 1;
	
	return 1;
}

void del(object pet)
{
	pet->delete_temp("feeded");
}

int help(object me)
{
	write(@HELP
指令格式 : feed <飼料> to <動物名>

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
