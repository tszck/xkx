// Room: /d/nanshaolin/putiyuan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
string look_mirror();
string look_zuo();
string look_jie();

void create()
{
    set("short", "菩提院");
    set("long", @LONG
一座偏僻陰暗的佛殿，殿上並排排列着三尊佛像，佛像前裝着一座
屏風，屏風上鑲嵌着一塊極大的銅鏡(mirror)。擦的晶光淨亮。佛像下
是一個神座 (zuo)，擺着兩盞發出豆黃光暈的油燈。昏黃的燈光下，依
稀見到鏡上鐫有幾句佛偈 (jie)。屏風前有幾個蒲團，幾個青年僧人正
在閉目打坐，東面是一片槐樹林。
LONG );
    set("exits", ([
        "east" : __DIR__"huaishu1",
           ]));
    set("item_desc",([
        "mirror" : (: look_mirror :),
        "zuo"    : (: look_zuo :),
        "jie"    : (: look_jie :),
    ]));
    set("objects",([
        CLASS_D("nanshaolin") + "/dayang" : 1,
        __DIR__"npc/xiao-ku" : 1,
    ]));
    set("coor/x", 1780);
    set("coor/y", -6220);
    set("coor/z", 10);
    setup();
}

string look_mirror()
{
    return "一個巨大的青銅鏡，鑲在屏風上，可清楚的看到殿上衆人的背影。\n";
}

string look_jie()
{
    return
    "    ****************************************\n"
    "    ********                        ********\n"
    "    ********    一切有爲法，        ********\n"
    "    ********                        ********\n"
    "    ********    如夢幻泡影，        ********\n"
    "    ********                        ********\n"
    "    ********    如露亦如電，        ********\n"
    "    ********                        ********\n"
    "    ********    當做如是觀。        ********\n"
    "    ********                        ********\n"
    "    ****************************************\n";
}

string look_zuo()
{
    return "這是一個黃揚木製的大神座上面支撐着三座佛像。\n";
}
