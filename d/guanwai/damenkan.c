// /guanwai/damenkan.c

inherit ROOM;

void create()
{
	set("short", "大門坎子");
	set("long", @LONG
這裏是沿江向東的古道，多為進山採參的參客所走，因此也稱“參
路”。前面一座小山截斷去路，因其行似門坎，且為東去採參的第一道
屏障，故被稱為大門坎子。西面是寬闊的松花江。松花江在冬春時結冰
可通行，夏秋化凍你只好找船家幫忙了。
LONG );
	set("exits", ([
		"southeast"  : __DIR__"ermenkan",
		"west"       : __DIR__"bingmian",
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("outdoors", "guanwai");
	set("coor/x", 6100);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	object obj, *ob;
	int i,j;

	if (dir=="west")
	{
		if ((strsrch(NATURE_D->game_time(), "一月") >= 0) ||
			(strsrch(NATURE_D->game_time(), "二月") >= 0) ||
			(strsrch(NATURE_D->game_time(), "三月") >= 0) ||
			(strsrch(NATURE_D->game_time(), "四月") >= 0) ||
			(strsrch(NATURE_D->game_time(), "五月") >= 0))
		{
			message_vision("$N見江面結凍，便壯起膽子踩冰而過。\n\n", me);
			if (random(me->query_dex())<20)
			{
				me->receive_wound("qi",20);
				me->receive_damage("qi",20);
			message_vision("$N只覺得腳下一滑，全身騰空而起，結結實實的摔在了冰面上！\n", me);
			}
			return 1;
		}
		else
		{
			j = 0;
			ob = all_inventory(environment(me));
			for(i=0; i<sizeof(ob); i++)
			{
				if ( (!userp(ob[i])) && (ob[i]->query("id")=="chuan fu"))
					j = 1;
			}
			if (j == 0)
			{
				obj = new(__DIR__"npc/chuanfu1");
				obj -> move(environment(me));
			message_vision("坎後走出一個船伕，站在邊上瞪着眼看着$N。", me);
			}
			else
			message_vision("船伕在旁邊拿眼瞪着$N看。", me);
			return notify_fail("冰面化凍，還是乘船吧！\n");
		}
	}
	return 1;
}
