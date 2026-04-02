// Room: /d/wudujiao/taohua.c

inherit ROOM;

void create()
{
        set("short", "桃花峪");
        set("long", @LONG
你走在兩山相夾的峽谷中，山上山下全是無邊的野桃樹，一陣
山風吹來，落英繽紛。數百年落下的桃花，桃枝都堆積在地上，人
走在上面軟軟的。日近正午了，遠處山林間似乎飄蕩着一股輕霧，
越來越濃。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"wdsl1",
                "northwest" : __DIR__"xiao3",
        ]));

	set("coor/x", -44980);
	set("coor/y", -81050);
	set("coor/z", 0);
	setup();
}
int valid_leave (object who, string dir)
{
        if(dir=="northwest"){
//      who->move("d/wudujiao/xiao3");
//      return 1;
            return ::valid_leave(who, dir);
        }
        else{
            if ((string)who->query("family/family_name")!="五毒教")
            {
                if(!(present("xingjun san", who))){
                    message_vision ("一陣濃香襲來，$N頓時覺得頭重腳輕。\n",who);
                    who->receive_damage("qi", 50);
                    remove_call_out ("fall_down");
                    call_out ("fall_down",1,who,environment(who));
                    who->start_busy(1,1);
                    return notify_fail("你禁不住踉蹌了幾下，兩腿突然一軟。\n");
//    who->unconcious();
                }
            }
            return 1;
        }
}

void fall_down (object who, object where)
{
        who->move(where);
        this_player()->unconcious();
}
void fall_down1 (object who, object where)
{
        this_player()->unconcious();
}