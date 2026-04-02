// Room: /d/guiyun/jiugong.c
// Last Modified by winder on Jul. 9 2001

void init()
{
	object ob=this_player();
	int i, temp, count;

	if (!ob->query_temp("jiugong"))
	{
		ob->set_temp("jiugong", 1);
		ob->set_temp("jiugong_0", 0);
		count = 45;
		for (i = 1; i <= 5; i++)
		{
			temp = random(10);
			ob->set_temp("jiugong_" + i, temp);
			count -= temp;
		}
		for (; i <= 8; i++)
		{
			temp = random(count > 9 ? 10 : count);
			ob->set_temp("jiugong_" + i, temp);
			count -= temp;
		}
		ob->set_temp("jiugong_9", count);
	}
	temp = ob->query_temp("jiugong_" + HERENO);
	if (temp > 0)
		set("long","這是一片茂密的桃花叢，你一走進來就迷失了方向。地上有" + chinese_number(ob->query_temp("jiugong_" + HERENO)) + "株桃花(taohua)。\n");
	else
		set("long","這是一片茂密的桃花叢，你一走進來就迷失了方向。地上一株桃花(taohua)也沒有。\n");
	add_action("do_drop", "drop");
	add_action("do_look", "look");
	add_action("do_get", "get");
	add_action("do_inv", "inventory");
	if (ob->query_temp("step_count") > 99)
	{
		ob->delete_temp("step_count");
		write("你在陣中累得精疲力盡，終因體力不支而昏了過去！\n");
		write("迷迷胡胡中似乎有人把你背出了陣。\n");
		ob->delete_temp("jiugong");
		for (i = 0; i <= 9; i++)
			ob->delete_temp("jiugong_" + i);
		ob->unconcious();
		if (ob->query_temp("jiugong_dir") == "w") 
			ob->move(__DIR__"road4", 1);
		else 
			ob->move(__DIR__"shiqiao", 1);
		message("vision","卻見花影閃爍，樹叢忽然現出一個缺口，幾個莊丁將一個昏迷不醒的傢伙扔了出來。\n", environment(ob), ob);
		return;
	}
	ob->add_temp("step_count", 1);
	return;
}

int do_look(string arg)
{
	object ob=this_player();
	int temp;

	if (!arg) {
		temp = ob->query_temp("jiugong_" + HERENO);
		if (temp > 0)
			set("long","這是一片茂密的桃花叢，你一走進來就迷失了方向。地上有" + chinese_number(ob->query_temp("jiugong_" + HERENO)) + "株桃花(taohua)。\n");
		else
			set("long","這是一片茂密的桃花叢，你一走進來就迷失了方向。地上一株桃花(taohua)也沒有。\n");
	}
	else if (arg=="west" || arg=="east" || arg=="north" || arg=="south")
		{
			write("你看不清那邊的情況！\n");
			return 1;
		}
	ob->look(arg);
}

string inv_desc(object ob)
{
	return sprintf("%s%s",
		ob->query("equipped")? HIC "□" NOR:"  ",
		ob->short()
	);
}

int do_inv(string arg)
{
	int temp;
	object *inv;
	object ob = this_player();

	if (arg && arg != ob->query("id")) return 0;

	inv = all_inventory(ob);
	temp = ob->query_temp("jiugong_0");
	if (temp > 0)
		printf("你身上帶著下列這些東西(負重 %d%%)：\n  " + chinese_number(ob->query_temp("jiugong_0")) + "株桃花(taohua)\n%s\n", (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(), implode(map_array(inv, "inv_desc", this_object()), "\n") );
	else
		printf("你身上帶著下列這些東西(負重 %d%%)：\n%s\n", (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(), implode(map_array(inv, "inv_desc", this_object()), "\n") );
	return 1;
}

int do_get(string arg)
{
	int amount, herenum;
	string taohua;
	object ob=this_player();

	if (!arg || sscanf(arg, "%d %s", amount, taohua) != 2)
		return 0;
	if (taohua != "taohua") return 0;
	
	herenum = ob->query_temp("jiugong_" + HERENO);
	if (herenum < 1) return notify_fail("這裏根本沒有桃花。\n");
	if (amount > herenum) return notify_fail("這裏沒有那麼多株桃花。\n");
	ob->set_temp("jiugong_" + HERENO, herenum - amount);
	ob->add_temp("jiugong_0", amount);
	write("你撿起" + chinese_number(amount) + "株桃花。\n");
	return 1;
}	

int do_drop(string arg)
{
	int i, amount;
	int *num = ({0,0,0,0,0,0,0,0,0,0});
	string taohua;
	object ob=this_player();

	if (!arg || sscanf(arg, "%d %s", amount, taohua) != 2)
		return 0;
	if (taohua != "taohua") return 0;
	
	for (i = 0; i <= 9; i++)
		num[i] = ob->query_temp("jiugong_" + i);
	if (num[0] < 1) return notify_fail("你的背囊里根本沒有桃花。\n");
	if (amount>num[0]) return notify_fail("你的背囊裏沒有那麼多株桃花。\n");
	num[HERENO] += amount;
	num[0] -= amount;
	ob->set_temp("jiugong_" + HERENO, num[HERENO]);
	ob->set_temp("jiugong_0", num[0]);
	write("你丟下" + chinese_number(amount) + "株桃花。\n");
	if (num[0] == 0)
	{
		if (num[1] + num[2] + num[3] == 15 &&
			num[4] + num[5] + num[6] == 15 &&
			num[7] + num[8] + num[9] == 15 &&
			num[1] + num[4] + num[7] == 15 &&
			num[2] + num[5] + num[8] == 15 &&
			num[3] + num[6] + num[9] == 15 &&
			num[1] + num[5] + num[9] == 15 &&
			num[3] + num[5] + num[7] == 15)
		{
			write( "桃花陣中忽然發出一陣“軋軋”的聲音，隨後現出一條道路，你趕忙走了出去。\n");
			ob->delete_temp("jiugong");
			ob->delete_temp("step_count");
			if (ob->query_temp("jiugong_dir") == "w")
			{
				tell_room(__DIR__"shiqiao","卻見花影閃爍，樹叢忽然現出一個缺口，" + ob->name() + "閃身而出。\n", ({}));
				ob->move(__DIR__"shiqiao");
			}
			else
			{
				tell_room(__DIR__"road4","卻見花影閃爍，樹叢忽然現出一個缺口，" + ob->name() + "閃身而出。\n", ({}));
				ob->move(__DIR__"road4");
			}
		}
	}
	return 1;
}
