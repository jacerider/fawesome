/**
 * @file
 * Javascript for Fawesome Field
 */
(function ($) {
  Drupal.behaviors.fawesome_fapi = {
    attach: function(context, settings) {
      if(settings.fawesome && settings.fawesome.icons){
        $('.fawesome-select').once(function(){
          var self = this;

          $('.fawesome-select-ops', self).click(function(e){
            e.preventDefault();
          });

          $('.fawesome-select-clear', self).click(function(e){
            e.preventDefault();
            $('.fawesome-select-select i', self).removeAttr('class');
            $('input', self).val('');
          });

          $('input', self).iconpicker({
            icons: settings.fawesome.icons,
            // inputSearch: true,
            placement:'bottomLeft',
            hideOnSelect: true,
            container: '.fawesome-select-wrapper',
            component: '.fawesome-select-ops',
          }).on('iconpickerSelected', function(e) {
            $('input', self).val(e.iconpickerValue);
          }).on('iconpickerShown', function(e) {
            $('.iconpicker-search', self).focus();
          });
        });
      }
    }
  }
})(jQuery);
