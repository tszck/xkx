// Room: /d/wudujiao/jiang2.c

#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
        set("short", "桃花江東岸");
        set("long", @LONG
這裏是桃花江邊，江水清澈，水流平緩，兩岸都是無邊的桃
樹，不斷有桃花隨風飄入江中，隨波逐流。江邊停泊着一條漁船。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"cun1",
                "south" : __DIR__"xiao1",
        ]));

	set("coor/x", -45000);
	set("coor/y", -81010);
	set("coor/z", 0);
  set("yell_about", "船家");             // yell 船家
  set("river_type", "江");               // 江面上傳來回響
  set("need_dodge",300);                 // 需要多少輕功
  set("come_msg_out",   "一葉扁舟緩緩地駛了過來，艄公將一塊踏腳板搭上堤岸，以便乘客上下。\n");
  set("busy_msg",       "只聽得江面上隱隱傳來：“別急嘛，這兒正忙着吶……”\n");
  set("wait_msg",       "岸邊一隻渡船上的老艄公說道：正等着你呢，上來吧。\n");
  set("leave_msg_out",  "艄公把踏腳板收了起來，竹篙一點，扁舟向江心駛去。\n");
  set("leave_msg_in",   "艄公把踏腳板收起來，說了一聲“坐穩嘍”，竹篙一點，扁舟向江心駛去。\n");
  set("come_msg_in",    "艄公說“到啦，上岸吧”，隨即把一塊踏腳板搭上堤岸。\n");
  set("item_desc/river", HIC "\n只見近岸處有一條漁船，也許大聲喊("
                         HIY "yell" HIC ")一聲船家(" HIY "boat" HIC
                        ")就\n能聽見。倘若你自負輕功絕佳,也可直接"
                        "渡水(" HIY "cross" HIC ")踏江而過。\n" NOR);
  set("boat_short", "渡船");    
  set("boat_desc",  @LONG
一葉小舟，最多也就能載七、八個人。一名六十多歲的老艄公
手持長竹篙，正在船尾喫力地撐着船。
LONG );
  set("to",         __DIR__"jiang1");  // 船的終點 /*   必選   */
	setup();
}