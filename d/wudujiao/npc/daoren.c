// daoren.c
inherit NPC;
int ask_me();
#include <ansi.h>

void create()
{
        set_name("毒郎中", ({ "dao ren","dao" }) );
        set("gender", "男性" );
        set("age", 35);
        set("per", 20);
        set("long", "一位身穿道服，乾癟黑瘦的中年道人．\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set_skill("dodge", 80);
        set_skill("unarmed",80);
        set_skill("parry", 80);
        set_skill("literate", 150);

        set("chat_chance",12);
        set("chat_msg",({
            "毒郎中冷笑道：江湖中人誰敢和我們五毒教作對，管叫他死的不明不白。\n",
            "毒郎中乾笑一聲道：貧道專管練制各種毒藥，保證藥到命除。\n",
        }));

        setup();
        add_money("silver", 20);
        set("inquiry", ([
            "name": "在下就是毒郎中．\n",
            "here": "此乃煉丹房，可以在這裏練制(lianzhi)各種毒藥。\n",
            "毒藥": "閣下可以使用(lianzhi)命令練制各種毒藥。\n",
            "毒經": (: ask_me :),
            "配方": (: ask_me :),
            "毒藥配方": (: ask_me :),
        ]) );
        carry_object("/d/wudang/obj/greenrobe")->wear();
}
int ask_me()
{
        object ob,me,book;
        me = this_player();
        if ((string)me->query("family/family_name") != "五毒教")
              return notify_fail("閣下與本派並無淵源，這是從那裏話來？\n");
        book=present("jing",me);
        if(objectp(book) && (string)book->query("name")=="毒經上篇")
              return notify_fail("你不是有一本了嗎，怎麼還來要？\n");
        command("say 此乃我五毒教之《毒經》，千萬不可遺失了啊。\n");
        ob = new("/clone/book/poisonbook1");
        ob->move(this_player());
        return 1;
}

