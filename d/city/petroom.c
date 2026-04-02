// Room: /d/petroom.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "寵物鋪");
	set("long", @LONG
這時一間寵物鋪。高高的櫃枱後坐着一個老頭。老頭的身後是一排
排的籠子，五花八門的養了不少東東，櫃枱上擺着的牌子 (paizi)列出
了寵物種類，你想要就購買(goumai)一隻吧。老頭還兼賣各種寵物的飼
料寵物，隨便買都成。寵物玩膩了不想玩，想換個種，也可以把舊的寵
物返還(return)給老頭，然後再買一隻新的。
LONG );
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : HIR"
                                 揚州寵物店"HIC"

   ┏--"HIM"寵物"HIC"--"HIM"名稱"HIC"--------"HIM"價目"HIC"--------┳--"HIM"寵物"HIC"--"HIM"名稱"HIC"--------"HIM"價目"HIC"--------┓"HIC"
   ┃  "HIG"龍   dragon     "HIY"九十九兩黃金"HIC"  ┃  "HIG"鳳凰 phenix     "HIY"九十九兩黃金"HIC"  ┃
   ┃  "HIG"麒麟 kylin      "HIY"九十九兩黃金"HIC"  ┃  "HIG"象   elephant   "HIY"四十九兩黃金"HIC"  ┃
   ┃  "HIG"獅   lion       "HIY"四十九兩黃金"HIC"  ┃  "HIG"虎   tiger      "HIY"四十九兩黃金"HIC"  ┃
   ┃  "HIG"豹   panther    "HIY"四十九兩黃金"HIC"  ┃  "HIG"雕   vulture    "HIY"四十九兩黃金"HIC"  ┃
   ┃  "HIG"熊   bear       "HIY"三十九兩黃金"HIC"  ┃  "HIG"狐   fox        "HIY"三十九兩黃金"HIC"  ┃
   ┃  "HIG"狼   wolf       "HIY"三十九兩黃金"HIC"  ┃  "HIG"狗   dog        "HIY"三十九兩黃金"HIC"  ┃
   ┃  "HIG"豬   pig        "HIY"三十九兩黃金"HIC"  ┃  "HIG"鱷   crocodile  "HIY"三十九兩黃金"HIC"  ┃
   ┃  "HIG"馬   horse      "HIY"三十九兩黃金"HIC"  ┃  "HIG"驢   donkey     "HIY"二十九兩黃金"HIC"  ┃
   ┃  "HIG"牛   cattle     "HIY"二十九兩黃金"HIC"  ┃  "HIG"猴   monkey     "HIY"二十九兩黃金"HIC"  ┃
   ┃  "HIG"鷹   eagle      "HIY"二十九兩黃金"HIC"  ┃  "HIG"鹿   deer       "HIY"二十九兩黃金"HIC"  ┃
   ┃  "HIG"蛇   snake      "HIY"十九兩黃金"HIC"    ┃  "HIG"貂   marten     "HIY"十九兩黃金"HIC"    ┃
   ┃  "HIG"貓   cat        "HIY"九兩黃金"HIC"      ┃  "HIG"鼠   mouse      "HIY"九兩黃金"HIC"      ┃
   ┃  "HIG"兔   rabbit     "HIY"九兩黃金"HIC"      ┃  "HIG"龜   tortise    "HIY"九兩黃金"HIC"      ┃
   ┃  "HIG"雞   chicken    "HIY"九兩黃金"HIC"      ┃  "HIG"鴨   duck       "HIY"九兩黃金"HIC"      ┃
   ┗--------------------------------┻--------------------------------┛"HIB"
        goumai：購買    return：返還    zancun：暫存    lingqu：領取
\n"NOR,
	]));
	set("exits", ([
		"northeast" : __DIR__"caohebeijie",
	]));
	set("objects", ([
		__DIR__"npc/oldman" : 1,
	]));
	set("coor/x", -30);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
