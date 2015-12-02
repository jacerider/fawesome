<?php

function fawesome_element_info() {
   return array('fawesome_select' => array(
     '#input' => TRUE,
     '#theme' => array('fawesome_select'),
     '#theme_wrappers' => array('form_element'),
     '#process' => array('fawesome_select_process'),
     '#element_validate' => array('fawesome_select_validate'),
  ));
}

/**
 * Process callback for Fawesome select field.
 */
function fawesome_select_process($element, &$form_state, $complete_form) {
  if($element['#value'] && strpos($element['#value'], 'fa-') === FALSE){
    $element['#value'] = 'fa-' . $element['#value'];
  }
  return $element;
}

/**
 * Validate callback for Fawesome select field.
 */
function fawesome_select_validate($element, &$form_state){
  // Consolidate into the three parts into one combined value.
  $value = str_replace('fa-', '', $element['#value']);
  form_set_value($element, $value, $form_state);
  return $element;
}

/**
 * Returns HTML for a fawesome_select form element.
 *
 * @param $vars
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #title, #value, #description, #size, #maxlength,
 *     #required, #attributes.
 *
 * @ingroup themeable
 */
function theme_fawesome_select($vars) {
  $element = $vars['element'];
  $element['#default_value'] = !empty($element['#default_value']) ? 'fa-' . $element['#default_value'] : '';
  $element['#attributes']['type'] = 'fawesome-select';
  $element['#attributes']['class'][] = 'element-hidden';
  element_set_attributes($element, array('id', 'name', 'value', 'size', 'maxlength'));
  _form_set_class($element, array('form-fawesome-select'));

  $icons = array();
  foreach(fawesome_list() as $icon){
    $icons[] = 'fa-' . $icon;
  }

  drupal_add_library('fawesome', 'fawesome.fapi');
  drupal_add_js(array('fawesome' => array('icons' => $icons)), 'setting');

  $output = '<div class="fawesome-select">';
  $output .= '<span class="prefix fawesome-select-wrapper">';
  $output .= '<a href="#" class="fawesome-select-ops">';
  $output .= '<span class="fawesome-select-select">&nbsp;<i class="fa"></i>&nbsp;</span>';
  $output .= '<span class="fawesome-select-browse">' . t('Browse') . '</span>';
  $output .= '</a>';
  $output .= '<a href="#" class="fawesome-select-clear">';
  $output .= t('Clear');
  $output .= '</a>';
  $output .= '</span>';
  $output .= '<input' . drupal_attributes($element['#attributes']) . ' />';
  $output .= '</div>';

  return $output;
}
