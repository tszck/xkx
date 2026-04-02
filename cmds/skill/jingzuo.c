// jingzuo.c
// Dec.11 1997 by Venus

void wakeup(object me, object where);
void del_jingzuoed(object me);

int main(object me, string arg)
{
	mapping fam;
	object where = environment(me);

	seteuid(getuid());

	if ((!(fam = me->query("family")) || fam["family_name"] != "峨嵋派"))
		return notify_fail("只有峨嵋派才能靜坐！\n");
	if (where->query("no_sleep_room"))
		return notify_fail("這裏太紛雜，你沒法靜心靜坐。\n");
	if (!where->query("sleep_room"))
		return notify_fail("這裏太紛雜，你沒法靜心靜坐。\n");
	if (me->query("eff_jing")<50)
		return notify_fail("你受傷太重，沒法靜坐。\n");
	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("戰鬥中想靜坐？你不要命啦！\n");
	me->save();
	if (me->query("betrayer") > 0)
		return notify_fail("別派叛徒，如何習練我峨嵋絕頂心法？\n");
	if (me->query("mud_age") - me->query("jingzuo_time") < 180)
		return notify_fail("你剛才靜坐過，現在頭腦一片空白。\n");
	if (me->query_skill("mahayana",1) < 40)
		return notify_fail("你的大乘般涅磐功還太淺薄了，沒法靜心靜坐。\n");
	if (me->query_skill("linji-zhuang",1) < 40)
		return notify_fail("你的臨濟莊實在太低了，沒法靜心靜坐。\n");
	if (where->query("sleep_room"))
	{
		write("你往牀上盤膝一坐，開始靜坐。\n");
		write("不一會兒，你神遊天外，物我兩忘。\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N一躬身，坐在牀上，閉目端念，靜心打坐。\n",me);
		where->add_temp("jingzuo_person", 1);

		me->set("no_get", 1);
		me->set("no_get_from", 1);
//		me->disable_player("<靜坐中>");
		me->set_temp("noliving/jingzuo", 1);
		call_out("wakeup",random(45)+1 , me, where);

		return 1;
	} else return notify_fail("這裏太紛雜，你沒法靜心靜坐。\n");
}

void wakeup(object me,object where)
{
	int skillslvl,addp,addc,exppot,intpot;

	skillslvl = (int) me->query_skill("mahayana",1);
	exppot = (int)(me->query("combat_exp")/20000);
	intpot = (int)(me->query_int()/10);
	addp = (int)(random(skillslvl)/5+intpot);
	addc = (int)(random(skillslvl)/3+exppot);
	if (addp > 200) addp = random(200);
	if (addc > 400) addc = random(400);
	me->receive_damage("jing", 15);
	me->receive_wound("jing", 3);
	me->add("potential",addp);
	me->add("combat_exp",addc);
//	me->enable_player();
	me->delete_temp("noliving");
	message_vision("$N靜坐完畢，緩緩睜眼，長長吐了一口氣。\n",me);
	me->set_temp("block_msg/all", 0);
	me->set("jingzuo_time", me->query("mud_age"));
//	write("你靜坐完畢，好累的感覺。\n");
        tell_object(me, "你靜坐完畢，好累的感覺。\n");
	where->add_temp("jingzuo_person", -1);
	me->delete("no_get");
	me->delete("no_get_from");
	return;
}

int help(object me)
{
	write(@HELP
指令格式 : jingzuo <精氣點數>

    這個指令是峨嵋派弟子用以靜坐修道的命令.

HELP
        );
        return 1;
}
