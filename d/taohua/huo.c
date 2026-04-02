// Room: /d/taohua/huo.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", HIR"火"NOR);
	set("long", @LONG
這裏是五行層的火，你一走下來，往上的鐵梯就被撤掉了。五行層
的構局互相連通，進入後就迷失了方向。每一行與其他四行的關係是生、
被生、克、被克。
LONG
	);
	set("exits", ([ 
		"shui" : __DIR__"shui",
		"tu" : __DIR__"tu",
		"mu" : __DIR__"mu",
		"jin" : __DIR__"jin",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8520);
	set("coor/y", -4680);
	set("coor/z", -10);
	setup();
}

void init()
{
	mixed *local;
	string tempstr;
	object me = this_player();
	int *month_map = ({1,1,1,1,2,2,2,2,-1,-1,-1,-1});

	add_action("do_save", "save");
	add_action("do_quit", "quit");
	if (!me->query_temp("liangyi")) 
		me->set_temp("liangyi", -1);
	if (!me->query_temp("sixiang")) 
		me->set_temp("sixiang", -1);
	if (!me->query_temp("wuxing")) {
		local = localtime(time());
		me->set_temp("wuxing", month_map[local[LT_MON]]);
		me->set_temp("wuxing_total", 12);
		me->set_temp("wuxing_step", 1);
		me->set_temp("wuxing_error", 1);
		tempstr = "由於";
		if (me->query_temp("liangyi") < 0) tempstr += "誤斷兩儀";
		if (me->query_temp("sixiang") < 0) tempstr += "亂入四象";
		if (me->query_temp("wuxing") < 0) tempstr += "錯踏五行";
		me->set_temp("last_damage_from", tempstr + "，觸發陣中機關而被射");
	}
	if (me->query_temp("sixiang") < 0 || me->query_temp("liangyi") < 0) 
		me->set_temp("wuxing", -1);
	if (me->query_temp("wuxing_error") >= 12) {
		tempstr = "由於你";
		if (me->query_temp("liangyi") < 0) tempstr += "誤斷兩儀、";
		if (me->query_temp("sixiang") < 0) tempstr += "亂入四象、";
//		if (me->query_temp("wuxing") < 0) tempstr += "錯踏五行";
		write(tempstr + "錯踏五行，被一股大力甩出了陣，正好摔到山腳下的一塊岩石上！\n"); 
		me->delete_temp("wuxing");
		me->delete_temp("liangyi");
		me->delete_temp("sixiang");
		me->delete_temp("wuxing_total");
		me->delete_temp("wuxing_step");
		me->delete_temp("wuxing_error");
		me->unconcious();
		me->move(__DIR__"shore", 1);
		return;
	}
	if (me->query_temp("wuxing_step") >= me->query_temp("wuxing_total")) {
		write("你將五行踏遍，終於穿出了迷陣，從高臺底層走了出來。\n"); 
		me->delete_temp("wuxing");
		me->delete_temp("liangyi");
		me->delete_temp("sixiang");
		me->delete_temp("wuxing_total");
		me->delete_temp("wuxing_step");
		me->delete_temp("wuxing_error");
		me->move(__DIR__"tomb", 1);
		return;
	}
}

int do_save()
{
	write("這裏不準存盤！\n");
	return 1;
}

int do_quit()
{
	write("這裏不準退出！\n");
	return 1;
}

int valid_leave(object me, string dir)
{
	int wuxing = me->query_temp("wuxing");

	if (dir == "shui" || dir == "tu" || dir == "mu" || dir == "jin") {
		if (wuxing < 0) {
			write("陣中機關忽然大作，數道青芒紅芒擊中了你，你只覺全身痛楚，意識也有些模糊了！\n");
			me->receive_wound("jing", 50);
			me->receive_wound("qi", 50);
			me->add_temp("wuxing_error", 1);
		}
		else {
			switch (dir) {
				case "jin":
					if (wuxing == 1) {
						write("陣中機關忽然發作，一道紅芒擊中了你，你只覺一陣痛楚！\n");
						me->receive_damage("qi", 40);
						me->add_temp("wuxing_error", 1);
					}
					else
						me->add_temp("wuxing_step", 1);
					break;

				case "mu":
					if (wuxing == 1) {
						me->add_temp("wuxing_total", 1);
					}
					else {
						write("陣中機關忽然大作，數道青芒紅芒擊中了你，你只覺全身痛楚，意識也有些模糊了！\n");
						me->receive_wound("jing", 40);
						me->receive_wound("qi", 40);
						me->add_temp("wuxing_error", 1);
					}
					break;

				case "shui":
					if (wuxing == 1) {
						write("陣中機關忽然大作，數道青芒紅芒擊中了你，你只覺全身痛楚，意識也有些模糊了！\n");
						me->receive_wound("jing", 40);
						me->receive_wound("qi", 40);
						me->add_temp("wuxing_error", 1);
					}
					else {
						me->add_temp("wuxing_total", 1);
					}
					break;

				case "tu":
					if (wuxing == 1) 
						me->add_temp("wuxing_step", 1);
					else {
						write("陣中機關忽然發作，一道青芒擊中了你，你只覺一陣暈眩！\n");
						me->receive_damage("jing", 40);
						me->add_temp("wuxing_error", 1);
					}
					break;
			}
		}
	}
	
	return ::valid_leave(me, dir);
}
