// Room: /d/taohua/tide.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "海中");
	set("long", @LONG
這裏是水底，除了迎面撲來的潮水(tide)外你什麼也看不見。
LONG
	);
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "tiao");
	add_action("do_hit", "hit");
	add_action("do_hit", "ji");
}

int do_jump(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("你正忙着呢！\n");
	if (arg != "bank" && arg != "anbian" && arg != "an" &&
		arg != "shore" && arg != "shatan")
		return notify_fail("你要往哪裏跳？\n");

	me->move("/d/jiaxing/haibin");
	message_vision("$N忽然從海水裏躥了出來，在空中輕輕一轉，落在了岸邊。\n", me);
	return 1;
}

int do_hit(string arg)
{
	object me = this_player();
	object weapon;
	int hit_tide, temp;

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if (arg != "tide" && arg != "chao")
	{
		write("你要擊打什麼？\n");
		return 1;
	}
	if (!(weapon = me->query_temp("weapon")))
	{
		write("你對着海潮拳打腳踢了一陣，終於發泄了心中對本ＱＵＥＳＴ的不滿。\n");
		return 1;
	}
	if (weapon->query("skill_type") != "sword")
	{
		write("你拿起" + weapon->query("name") + "對着海潮胡亂揮擊了一陣，覺得自己特無聊。\n");
		return 1;
	}
	if (me->query("neili") < 60)
	{
		write("你的內力不足，無法繼續練下去。\n");
		return 1;
	}
	if (me->query("qi") < 0)
	{
		write("你已經不行了，無法繼續練下去。\n");
		return 1;
	}
	if (weapon->query("material") != "wood" || me->query("benefit/str"))
	{
		hit_tide = weapon->query_temp("hit_tide");
		if (hit_tide == 0)
		{
			if (weapon->query("material") == "wood")
				weapon->set_temp("max_hit_tide", 5);	
			else if (weapon->query("material") == "steel")
				weapon->set_temp("max_hit_tide", 12);	
			else
				weapon->set_temp("max_hit_tide", 8);	
		}
		write("你用" + weapon->query("name") + "奮力擊打着海潮，於劍的運用方面有了一些領悟。\n");
		hit_tide++;
		if (hit_tide > weapon->query_temp("max_hit_tide")) {
			write("因爲你用力過猛，"+ weapon->query("name") + "“啪”地一聲折斷了！\n");
			destruct(weapon);
		}
		else
			weapon->set_temp("hit_tide", hit_tide);
		me->receive_damage("qi", 45);
		me->add("neili", -40);
		if (me->query_skill("sword",1) < 80)
			me->improve_skill("sword", me->query("int") / 2);
		return 1;
	}
	else
	{
		hit_tide = me->query("sea/hit_tide");
		write("你用" + weapon->query("name") + "奮力擊打着海潮，");
		hit_tide++;
		temp = hit_tide % 200;
		if (temp < 10)
			write(weapon->query("name") + "寂然無聲。");
		else if (temp < 20)
			write(weapon->query("name") + "發出了輕微的聲響。");
		else if (temp < 40)
			write(weapon->query("name") + "發出了嗤嗤的輕響。");
		else if (temp < 60)
			write(weapon->query("name") + "發出了刷刷的聲音。");
		else if (temp < 80)
			write(weapon->query("name") + "發出了呼呼的聲音。");
		else if (temp < 90)
			write(weapon->query("name") + "隱隱發出了轟轟的聲音。");
		else if (temp < 110)
			write(weapon->query("name") + "竟然發出了轟隆隆的巨聲。");
		else if (temp < 120)
			write(weapon->query("name") + "隱隱發出了轟轟的聲音。");
		else if (temp < 130)
			write(weapon->query("name") + "發出了呼呼的聲音。");
		else if (temp < 150)
			write(weapon->query("name") + "發出了刷刷的聲音。");
		else if (temp < 170)
			write(weapon->query("name") + "發出了嗤嗤的輕響。");
		else if (temp < 190)
			write(weapon->query("name") + "發出了輕微的聲響。");
		else
			write(weapon->query("name") + "寂然無聲。");
		write("你對於內功以及劍法都有了一些領悟。\n");
		if (!(hit_tide % 20))
		{
			write("因爲你用力過猛，"+ weapon->query("name") + "“啪”地一聲折斷了！\n");
			destruct(weapon);
		}
		me->set("sea/hit_tide", hit_tide);
		if (hit_tide >= 1400)
		{
			write("到了這個時候，你終於練到手中的木劍欲輕則輕欲響則響的境界！你的膂力增加了！\n");
			write("以後你恐怕無法再通過與海潮搏擊而獲得更深的內功修爲了！\n");
			me->add("str",1);
			me->set("benefit/str", 1);
			me->delete("sea/hit_tide");
		}
		me->receive_damage("qi", 50);
		me->add("neili", -50);
		if (me->query_skill("sword",1) < 120)
			me->improve_skill("sword", me->query("int"));
		if (me->query_skill("force",1) < 120)
			me->improve_skill("force", me->query("int"));
		return 1;
	}
	return 1;
}
