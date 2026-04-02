// Room: /d/nanshaolin/shanmen.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
void init();
int do_open();
int valid_leave();
string look_gate();

void create()
{
	set("short", "少林山門");
	set("long", @LONG
轉過山坳，舉目望去，山谷裏一大片房屋都是碧瓦黃牆，卻是一座
大叢林。到廟前抬頭一望，見山門(gate)正中金字寫着“少林古剎”四
個大字。原來這裏就是南少林寺。福建少林寺雖是嵩山下院，但南方莆
田少林下院的武功與嵩山少林一脈相傳，寺中僧人武功之強，不下嵩山
本寺。
LONG );
	set("outdoors", "nanshaolin");
	set("item_desc",([
		"gate" : (: look_gate :),
	]));
	set("objects", ([
		CLASS_D("nanshaolin")+"/yuantong" : 1,
		CLASS_D("nanshaolin")+"/fangqiong" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"guangchang",
	]));
	set("coor/x", 1820);
	set("coor/y", -6300);
	set("coor/z", 10);
	setup();
//	"/clone/board/nanshaolin_b"->foo();
}

void init()
{
	add_action("do_knock", "knock");
}

int close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"gchang-1")) )
		room = load_object(__DIR__"gchang-1");
	if(objectp(room))
	{
		delete("exits/north");
		message("vision","乒地一聲，裏面有人把大門關上了。\n",this_object());
		room->delete("exits/south");
		if (objectp(present("yuan tong", room)))
			message("vision","元痛上前把大門關了起來。\n",room);
		else message("vision","壯年僧人上前把大門關了起來。\n",room);
	}
	else message("vision", "ERROR: gate not found(close).\n", room);
}

int do_knock(string arg)
{
	object room;

	if (query("exits/north")) return notify_fail("大門已經是開着了。\n");

	if (!arg || (arg != "gate" && arg != "north"))
		return notify_fail("你要敲什麼？\n");

	if(!( room = find_object(__DIR__"gchang-1")) )
		room = load_object(__DIR__"gchang-1");
	if(objectp(room))
	{
		set("exits/north", __DIR__"gchang-1");
		message_vision("$N輕輕地敲了敲門，只聽吱地一聲，一位壯年僧人應聲打開大門，\n他用鋭利的目光上上下下打量着$N。\n", this_player());
		room->set("exits/south", __FILE__);
		message("vision","外面傳來一陣敲門聲，壯年僧人應聲上前把大門開。\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if ( dir != "north" )
	{
		return ::valid_leave(me, dir);
	}
	if ( (me->query("family/family_name") == "少林派") ||
		(me->query("family/family_name") == "南少林派"))
	{
		if (((int)me->query("guilty") == 0) &&
			((int)me->query("K_record") == ((int)me->query("PKS") + (int)me->query("MKS"))))
		{
			message_vision("壯年僧人側身讓開，説道：師兄辛苦了，請進。\n", me);
			return 1;
		}
		else
		{
			if((int)me->query("guilty") == 0)
			{
				if((int)me->query("shen_record") >
					(int)me->query("shen"))
					me->set("guilty", 1);
				else me->set("guilty", 2);
				me->set("K_record", me->query("PKS") + me->query("MKS"));
				me->set("shen_record", me->query("shen"));
			}
			write("壯年僧人沉下臉來，説道：戒律院主持大癲大師請師兄\n火速去戒律院陳述此行過犯。\n");
			return 1;
		}
	}
	else if( present("yingxiong ling", me) )
		{
			message_vision("壯年僧人合十為禮，側身讓開，説道：原來是貴客駕到，請進請進！\n", me);
			return 1;
		}
    
	if (me->query("shen") >= 0)
	{
		if (me->query("gender") == "女性")
		{
			return notify_fail("壯年僧人説道：這位女施主還是請回罷，本寺從不接待女客。\n");
		}
		else
		{
			return notify_fail("壯年僧人説道：這位施主請回罷，本寺不接待俗人。\n");
		}
	}

	return notify_fail("壯年僧人立時從身畔摯出一把雪亮的戒刀來，把明晃晃的\n刀尖對準你的胸口，橫眉怒目地説道：你等邪魔外道，還不給我滾開！\n以後再敢走近少林一步，我立時就斬斷你們的狗腿！\n");
}

string look_gate()
{
	return "一道三丈來高的硃紅杉木包銅大門。\n";
}
