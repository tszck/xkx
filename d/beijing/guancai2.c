inherit ROOM;

void create()
{
	set("short", "棺材店內室");
	set("long",
	     "\n一進門，一股腐臭讓你幾乎要窒息了。屋裏滿是棺材(guancai)。\n"
	);
	set("exits", ([
		"west" : __DIR__"guancai1",
	]));
	set("item_desc", ([
		"guancai" : "\n棺材板很結實，上面積了些灰塵。\n" ,
	]));
	set("no_clean_up", 0);
	set("coor/x", -218);
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
        if (!arg||arg!="guancai") return notify_fail("你要移開什麼？\n");
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
	if( arg=="guancai" ) {
		message_vision("\n$N試著敲了敲棺材板，咚咚，裏面似乎是空的。\n", this_player());
	}
	if( sscanf(arg, "guancai %s", dir)==1 ) 
	{
		if( dir=="3" || dir=="three") {
		if(!objectp(present("hole", environment(me))))
		{
		message_vision("\n$N在棺材板上咚咚咚敲了三下，只聽吱呀一聲，\n"+"裏邊伸出一雙手把棺材板掀開了。\n", this_player());
                hole = new(__DIR__"obj/hole");
                hole->move(__DIR__"guancai2");
		}
	        }   
		else return notify_fail("\n你胡亂敲了棺材板幾下，結果什麼也沒發生。\n");
	}		
return 1;
}

int do_enter(string arg)
{
 if( !arg || arg!="guancai" ) return 0;
 return notify_fail(" 想穿棺材板啊？你不會奇門遁甲。\n");
 return 1;
}	
