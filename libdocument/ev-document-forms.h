/* ev-document-forms.h
 *  this file is part of evince, a gnome document viewer
 * 
 * Copyright (C) 2007 Carlos Garcia Campos <carlosgc@gnome.org>
 *
 * Evince is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Evince is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef EV_DOCUMENT_FORMS_H
#define EV_DOCUMENT_FORMS_H

#include <glib-object.h>

#include "ev-document.h"
#include "ev-form-field.h"

G_BEGIN_DECLS

#define EV_TYPE_DOCUMENT_FORMS	          (ev_document_forms_get_type ())
#define EV_DOCUMENT_FORMS(o)	          (G_TYPE_CHECK_INSTANCE_CAST ((o), EV_TYPE_DOCUMENT_FORMS, EvDocumentForms))
#define EV_DOCUMENT_FORMS_IFACE(k)	  (G_TYPE_CHECK_CLASS_CAST((k), EV_TYPE_DOCUMENT_FORMS, EvDocumentFormsIface))
#define EV_IS_DOCUMENT_FORMS(o)	          (G_TYPE_CHECK_INSTANCE_TYPE ((o), EV_TYPE_DOCUMENT_FORMS))
#define EV_IS_DOCUMENT_FORMS_IFACE(k)     (G_TYPE_CHECK_CLASS_TYPE ((k), EV_TYPE_DOCUMENT_FORMS))
#define EV_DOCUMENT_FORMS_GET_IFACE(inst) (G_TYPE_INSTANCE_GET_INTERFACE ((inst), EV_TYPE_DOCUMENT_FORMS, EvDocumentFormsIface))

typedef struct _EvDocumentForms      EvDocumentForms;
typedef struct _EvDocumentFormsIface EvDocumentFormsIface;

struct _EvDocumentFormsIface
{
	GTypeInterface base_iface;

	/* Methods  */
	GList   *(* get_form_fields)                    (EvDocumentForms   *document_forms,
							 gint               page);
	gchar   *(* form_field_text_get_text)           (EvDocumentForms   *document_forms,
							 EvFormField       *field);
	void     (* form_field_text_set_text)           (EvDocumentForms   *document_forms,
							 EvFormField       *field,
							 const gchar       *text);
	gboolean (* form_field_button_get_state)        (EvDocumentForms   *document_forms,
							 EvFormField       *field);
	void     (* form_field_button_set_state)        (EvDocumentForms   *document_forms,
							 EvFormField       *field,
							 gboolean           state);
	gchar   *(* form_field_choice_get_item)         (EvDocumentForms   *document_forms,
							 EvFormField       *field,
							 gint               index);
	gint     (* form_field_choice_get_n_items)      (EvDocumentForms   *document_forms,
							 EvFormField       *field);
	gboolean (* form_field_choice_is_item_selected) (EvDocumentForms   *document_forms,
							 EvFormField       *field,
							 gint               index);
	void     (* form_field_choice_select_item)      (EvDocumentForms   *document_forms,
							 EvFormField       *field,
							 gint               index);
	void     (* form_field_choice_toggle_item)      (EvDocumentForms   *document_forms,
							 EvFormField       *field,
							 gint               index);
	void     (* form_field_choice_unselect_all)     (EvDocumentForms   *document_forms,
							 EvFormField       *field);
	void     (* form_field_choice_set_text)         (EvDocumentForms   *document_forms,
							 EvFormField       *field,
							 const gchar       *text);
	gchar   *(* form_field_choice_get_text)         (EvDocumentForms   *document_forms,
							 EvFormField       *field);
};

GType    ev_document_forms_get_type                            (void) G_GNUC_CONST;
GList   *ev_document_forms_get_form_fields                     (EvDocumentForms   *document_forms,
								gint               page);

gchar 	*ev_document_forms_form_field_text_get_text            (EvDocumentForms   *document_forms, 
								EvFormField       *field);
void 	 ev_document_forms_form_field_text_set_text            (EvDocumentForms   *document_forms, 
								EvFormField       *field, 
								const gchar       *text);

gboolean ev_document_forms_form_field_button_get_state         (EvDocumentForms   *document_forms,
								EvFormField       *field);
void 	 ev_document_forms_form_field_button_set_state         (EvDocumentForms   *document_forms, 
								EvFormField       *field, 
								gboolean           state);

gchar    *ev_document_forms_form_field_choice_get_item         (EvDocumentForms   *document_forms, 
								EvFormField       *field, 
								gint               index);
gint 	  ev_document_forms_form_field_choice_get_n_items      (EvDocumentForms   *document_forms, 
								EvFormField       *field);
gboolean  ev_document_forms_form_field_choice_is_item_selected (EvDocumentForms   *document_forms, 
								EvFormField       *field, 
								gint               index);
void 	  ev_document_forms_form_field_choice_select_item      (EvDocumentForms   *document_forms, 
								EvFormField       *field, 
								gint               index);
void 	  ev_document_forms_form_field_choice_toggle_item      (EvDocumentForms   *document_forms, 
								EvFormField       *field, 
								gint               index);
void 	  ev_document_forms_form_field_choice_unselect_all     (EvDocumentForms   *document_forms, 
								EvFormField       *field);
void 	  ev_document_forms_form_field_choice_set_text         (EvDocumentForms   *document_forms,
								EvFormField       *field,
								const gchar       *text);
gchar    *ev_document_forms_form_field_choice_get_text         (EvDocumentForms   *document_forms,
								EvFormField       *field);

G_END_DECLS

#endif /* EV_DOCUMENT_FORMS_H */