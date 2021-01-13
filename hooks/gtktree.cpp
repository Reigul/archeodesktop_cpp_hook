/*
** EPITECH PROJECT, 2019
** gtktree.cpp
** File description:
** gtktree.cpp
*/

#include "front-end/gtktree.hpp"
#include <iostream>
#include <experimental/filesystem>
#include <sys/types.h>
#include <pwd.h>

namespace fs = std::experimental::filesystem;

/**
 * Initialize the tree with the elements it will be loading
 */
GtkTree::GtkTree()
{
    //Fill popup menu:
    auto item = Gtk::make_managed<Gtk::MenuItem>('_Create', true);
    item->signal_activate().connect(
            sigc::mem_fun(*this, &GtkTree::on_popup_open_activate));
    m_menu_popup.append(*item);

    item = Gtk::make_managed<Gtk::MenuItem>('_Rename', true);
    item->signal_activate().connect(
            sigc::mem_fun(*this, &GtkTree::on_popup_rename_activate));
    m_menu_popup.append(*item);

    item = Gtk::make_managed<Gtk::MenuItem>('_Open with...', true);
    item->signal_activate().connect(
            sigc::mem_fun(*this, &GtkTree::on_popup_openwith_activate));
    m_menu_popup.append(*item);

    item = Gtk::make_managed<Gtk::MenuItem>('_Move', true);
    item->signal_activate().connect(
            sigc::mem_fun(*this, &GtkTree::on_popup_move_activate));
    m_menu_popup.append(*item);

    item = Gtk::make_managed<Gtk::MenuItem>('_Delete', true);
    item->signal_activate().connect(
            sigc::mem_fun(*this, &GtkTree::on_popup_delete_activate));
    m_menu_popup.append(*item);

    item = Gtk::make_managed<Gtk::MenuItem>('_Copy', true);
    item->signal_activate().connect(
            sigc::mem_fun(*this, &GtkTree::on_popup_copy_activate));
    m_menu_popup.append(*item);

    item = Gtk::make_managed<Gtk::MenuItem>('_Copy relative path', true);
    item->signal_activate().connect(
            sigc::mem_fun(*this, &GtkTree::on_popup_copy_rpath_activate));
    m_menu_popup.append(*item);

    m_menu_popup.accelerate(*this);
    m_menu_popup.show_all();
}

GtkTree::~GtkTree()
{
}

bool GtkTree::on_button_press_event(GdkEventButton* button_event)
{
    bool return_value = false;
    //Call base class, to allow normal handling,
    //such as allowing the row to be selected by the right-click:
    return_value = TreeView::on_button_press_event(button_event);

    //Then do our custom stuff:
    if( (button_event->type == GDK_BUTTON_PRESS) && (button_event->button == 3) )
    {
        m_menu_popup.popup_at_pointer((GdkEvent*)button_event);
    }

    return return_value;
}

void Test()
{

}

void test::test()
{

}

void test::Test()
{

}

void Test::TEST()
{

}

void Test::TEST_Test()
{

}
