//neishi.c

inherit ROOM;

void create()
{
	set("short", "內室");
	set("long",
	     "\n這裏是一個空蕩蕩的房間，除了地板(floor)，什麼也沒有。\n"
	);
	set("exits", ([
		"east" : __DIR__"huichunt",
	]));
	set("item_desc", ([
		"floor" : "\n地板全是木製的，上面積了些灰塵，不過有一塊木板很乾淨。\n" ,
	]));
	set("no_clean_up", 0);
	set("coor/x", -211);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_move", "move");
        add_action("do_move", "open");
        add_action("do_knock", "knock");
}


int do_move(string arg)
{
        object me;
        me = this_player();
        if (!arg||arg!="floor") return notify_fail("你要移開什麼？\n");
	message_vision(
		"\n$N掀開棺材板，只聽“唰”的一聲, 地道里突然白光一閃，\n"+
		"一柄長劍倏的伸出,“噗”的一聲刺入了$N的小腹,又“噗”的一聲拔了出來。\n"+
                "一個道人從洞裏探出頭來，滿臉不屑地看了$N一眼，又伸手把地板關上了。\n", this_player());
        if((int)this_player()->query("qi")<250) this_player()->die();
        else this_player()->unconcious();
	return 1;
}

int do_knock(string arg)
{
        object me,hole;
	string dir;
        me = this_player();
        if (!arg||arg=="") return 0;
	if( arg=="floor" ) {
		message_vision("\n$N試著敲了敲地板，聲響清脆，下面似乎是空心的。\n", this_player());
	}
	if( sscanf(arg, "floor %s", dir)==1 ) 
	{
		if( dir=="3" || dir=="three") {
		if(!objectp(present("hole", environment(me))))
		{
		message_vision("\n$N在木板上咚咚咚敲了三下，只聽吱呀一聲，\n"+"裏邊伸出一雙手把地板掀開了。\n", this_player());
                hole = new(__DIR__"obj/hole");
                hole->move(__DIR__"neishi");
		}
	        }   
		else return notify_fail("\n你胡亂敲了木板幾下，結果什麼也沒發生。\n");
	}		
return 1;
}

int do_enter(string arg)
{
 if( !arg || arg!="floor" ) return 0;
 return notify_fail(" 想穿地板啊？你不會奇門遁甲。\n");
 return 1;
}	
