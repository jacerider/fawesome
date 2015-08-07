/**
 * @file
 * Javascript for Fawesome Field
 */
(function ($) {
  Drupal.behaviors.fawesome_field = {
    attach: function(context, settings) {
      if(settings.fawesome_field && settings.fawesome_field.icons){
        $('.fawesome-field-icon').once(function(){
          var self = this;

          $('.fawesome-field-icon-ops', self).click(function(e){
            e.preventDefault();
          });

          $('.fawesome-field-icon-clear', self).click(function(e){
            e.preventDefault();
            $('.fawesome-field-icon-select i', self).removeAttr('class');
            $('input', self).val('');
          });

          $('input', self).iconpicker({
            icons: settings.fawesome_field.icons,
            // inputSearch: true,
            placement:'bottomLeft',
            hideOnSelect: true,
            container: '.fawesome-field-icon-wrapper',
            component: '.fawesome-field-icon-ops',
          }).on('iconpickerSelected', function(e) {
            $('input', self).val(e.iconpickerValue);
          });
        });
      }
    }
  }
})(jQuery);
