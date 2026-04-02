// shulin1.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","山谷");
       set("long", @LONG
你走進山谷，這裏林木茂密，有如仙境。只見兩山之間流出一條小溪來，
清澈的溪水從你腳邊靜靜地淌過。口渴的你正好可以飲(drink)個飽。
LONG);
        set("resource/water", 1);
        set("exits", ([
                "southeast" : __DIR__"shulin",
                "north" : "/d/gaochang/road",
        ]));
        set("outdoors", "hasake");
        set("no_quest",1);
        setup();
}


int do_drink(string arg)
{
        int current_water;
	int max_water;
        object me;
        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"用手捧起清水喝了幾口。\n", environment(me), ({me}));
            write("你只覺溪水微帶甜味，甚是清涼可口。\n");
            }
        else write("你喝不下了。\n");
        return 1;
}
void init()
{
/*        object ob = this_player();        
        if(interactive(ob) &&  ob->query_temp("li_meet") == 2) {
             ob->add_temp("li_meet", 1);
             new(__DIR__"obj/shoujuan2")->move(ob);
             write("
你發現樹枝上有一方李文秀留下的白手絹，原來在你暈倒後是她救了你出來。
你左右看了看，發現李文秀早就離開了，那這裏。。。這裏莫非就是。。。？\n");
        }        
*/        add_action("do_drink", "drink");
}